const byte PIN_MOTOR = 9;
const byte PIN_CH_A = 2;
const byte PIN_CH_B = 3;
const unsigned int ONE_REV = 2688;   // One revolution of the big wheel
const unsigned int ONE_TOOTH = 224;  // 32 stripes (64 on/off times) = one tooth of big wheel, 3.5 teeth of big wheel = 1 tooth of small wheel. 3.5 * 64 = 224
const unsigned long DIST = ONE_TOOTH;
const unsigned long SLOWDOWN = ONE_TOOTH * 2; // slow down when within 4 teeth of arrival

const byte MOTOR_SPEED = 255;
const byte MOTOR_SLOW = 120;

volatile byte stateA = LOW;
volatile byte stateB = LOW;
volatile byte lastA = LOW;
volatile byte lastB = LOW;

volatile long counter = 0;
long counter_copy = 0;
long countTotal = 0;
long offset = 0;

byte motorSpeed = 0;
bool isMotorRunning = false;

String serialInput = "";

void setup() {
  Serial.begin(9600);
  Serial.print("Motor power enabled. Beginning setup...\n");
  
  pinMode(PIN_MOTOR, OUTPUT);
  
  pinMode(PIN_CH_A, INPUT);
  pinMode(PIN_CH_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_CH_A), interruptA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_CH_B), interruptB, CHANGE);

  motorSpeed = 0;
  Serial.print("System ready! awaiting input...\n");
  analogWrite(PIN_MOTOR, motorSpeed);
  isMotorRunning=false;
}

void interruptA(){
  lastA = stateA;
  stateA = !stateA;
  getRotation();
}

void interruptB(){
  lastB = stateB;
  stateB = !stateB;
  getRotation();
}

void getRotation(){
  if( (stateA==HIGH) && (stateB==HIGH) ){
    if( lastA==LOW ){
      counter++;
    } else {
      counter--;
    }
  } else
  if( (stateA==LOW) && (stateB==LOW) ){
    if( lastA==HIGH ){
      counter++;
    } else {
      counter--;
    }
  }
}

void loop() {
    // if a variable is larger than a byte (long in this case) the data can become
    // corrupt if an interrupt happens to fire during a read/write. So, temporarily
    // disable them to get the value.
    noInterrupts();
    if( counter_copy < 0 ) counter = 0; // negative values indicate a reset is necessary
    counter_copy = counter;
    interrupts();

  // If motor is off, get Serial input
  if( !isMotorRunning ){
    if( Serial.available() > 0 ){
      int inChar = Serial.read();
      if( isDigit(inChar) ) serialInput += (char)inChar;
      
      // Once a 'newline' character is received:
      if( inChar == '\n' ){
        countTotal = serialInput.toInt();
        serialInput = "";
        Serial.print("Received: ");
        Serial.print(countTotal);
        Serial.print("\nSpinning...\n");

        countTotal *= ONE_TOOTH; // Multiply to get number of teeth needed from the big wheel to advance the little wheel by one tooth
        motorSpeed = MOTOR_SPEED; // full speed ahead!
        isMotorRunning = true;
      }
    }
  }

  // Motor runs as long as the counter is less than the designated value
  if( isMotorRunning ){

    // Set a slow-down if we're getting close to destination
    if( (counter_copy + SLOWDOWN) > countTotal ) // within slow-down range, apply slower motor speed for accuracy/reduced inertia
      motorSpeed = MOTOR_SLOW;

    // set motor PWM
    analogWrite(PIN_MOTOR, motorSpeed);

    // if we reach our desired rev count
    if( counter_copy >= (countTotal - offset )){
    
      // Stop the motor, delay to let all moving components settle to a complete stop
      digitalWrite(PIN_MOTOR, LOW);
      delay(800);

      // Get rotor overspin - this offset will be subtracted from the next motor operation
      noInterrupts();
      offset = counter - counter_copy;
      interrupts();

      Serial.print("Spinning complete!\n\nAwaiting input...\n");

      // Rotor has stopped, reset counter
      counter_copy = -1;

      // stop motor, wait for next Serial input
      motorSpeed = 0;
      analogWrite(PIN_MOTOR, motorSpeed);
      isMotorRunning = false;
    }
  }
}

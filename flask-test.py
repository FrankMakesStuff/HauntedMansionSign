from flask import Flask, request, render_template
import serial
import time

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM3'
ser.timeout=0

app = Flask(__name__)

@app.route('/')
def main():
	return render_template('main.html')

@app.route('/', methods=['POST'])
def my_form_post():
	text = ""
	getData = ""

	text = request.form['text']
	numRevs = int(text)
	print numRevs

	ser.open()
	while getData.find("input") < 0:
		getData = getData + ser.readline()
		print getData
		time.sleep(1)

	ser.write(str(numRevs) + '\n')

	time.sleep(1)

	ser.close()

	templateData = {
		'getData' : getData,
                'numRevs' : numRevs
	}

	return render_template('form.html', **templateData)

if __name__ == "__main__":
	app.run(debug=True, host='0.0.0.0', port=80)

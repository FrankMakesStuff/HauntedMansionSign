# HauntedMansionSign
All the code and 3D files for my 3D-printed self-updating Haunted Mansion sign!

## About
The long-term goal of this project was to build a fan-made sign that would display the current wait-time of The Haunted Mansion, in Walt Disney World. I dunno, Disney fans have neat knick-knacks based on their fandom of the parks, so I had this idea of a little Haunted Mansion sign that would also show the current wait-time - my own personal little homage and link from my home to the park. Click the image below to watch it in action on YouTube:

[![Alt text](https://img.youtube.com/vi/Spqv1lANATA/0.jpg)](https://www.youtube.com/watch?v=Spqv1lANATA)

While I did not get that far, I was able to get the mechanics up and running, so here's the run-down of that. I salvaged a really cool motor from an old discarded printer. It had a rotary disc and optical encoder on the back of it, used for precise positioning, as is needed in desktop printers, scanners, etc. I ended up using interrupts to read the output from the encoder with an Arduino Nano, as the motor spun way too fast to get an accurate reading in the software main loop. As a consequence, I needed volatile access to the Arduino's memory within the interrupt to increment the counter value, which could cause the code to act funny -- this could probably be improved upon in later versions.

Lastly, I was able to expand the gear-train that came with the motor with my 3D printer, and I was able to use a really cool trick of swapping out filament colors during the print to get visible numbers (in white filament) on top of the (black) tooth-wheel. I had some fun figuring out the gear ratios and everything needed to call up any number on the wheel -- and that's basically where the project left off.

The rig could be controlled via serial access of the Arduino, but I expanded that a little using a Python script running Raspberry Pi that communicates serially to the Arduino - The idea being that, someday, if I ever do build this into my Haunted Mansion sign, it will simply sit on a shelf, the Pi communicates over the house Wi-Fi (using a really great library called [themeparks](https://github.com/cubehouse/themeparks) to get the actual real-time wait-time data from the parks, and update the motorized display, mimicking the real-life wait-time signs used at the theme parks.

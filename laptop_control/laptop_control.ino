#include <Servo.h> // calls up servo library
Servo motorRgt; // creates servo objects to control servos
Servo motorLft;//maximum of eight servo objects can be created

void setup() {
    Serial.begin(9600); // establishes serial connection

    motorRgt.attach(9); // attaches the servo on pin 9 to the servo object
    motorLft.attach(10); // attaches the servo on pin 10 to the servo object

    motorRgt.write(90); // starts bot at pause before any inputs
    motorLft.write(90); // motor controllers read 90 from the servo library as "stop"
}
//***NOTE:  numbers larger than 90 are forward with 180 being fastest and 91 slowest

//***numbers smaller than 90 are reverse with 0 being fastest and 89 slowest


void loop() {

    if (Serial.available()) {

        byte val = Serial.read();

        if (val == 'o') {
            for (int i = 91; i <= 121; i += 5) {
                motorRgt.write(i);
                motorLft.write(i);
                delay(333);
            }
        }


        if (val == 'p') {
            motorRgt.write(121);   //forward ***NOTE  because one motor side faces the opposite
            motorLft.write(121);  //dirrection on the bot, one motor is reversed to go forward.
        }

        if (val == 'l') {
            motorRgt.write(111); //left
            motorLft.write(131);
        }

        if (val == '\'') {
            motorRgt.write(131); //right
            motorLft.write(111);
        }

        if (val == ';') {
            motorRgt.write(70); //backwards
            motorLft.write(70);
        }
        if (val == '[' || val == '{' || val == 'k' || val == 'K' || val == 32) {
            motorRgt.write(91); //stop
            motorLft.write(91);
        }
    }

}

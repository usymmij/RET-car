/*  Joystick BreakOut Receiver
    this code receives and parses a
    serial string sent by the
    Joystick BreakOut_Send example code
    use example: wireless serial peer to peer
    comunication between Arduinos
    Written by Matt Fagen and Allan Bayntun
    editited by Johnathan Hsu TAS class of 2018
*/

#include <Servo.h>
Servo Lmotor;
Servo Rmotor;
int stopSpeed = 90;

void setup() {
    Serial.begin(9600);
    Lmotor.attach(9); // left motor connects to channel 1 on motor controller
    Rmotor.attach(10); // right motor = ch2

    Lmotor.write(90);
    Rmotor.write(90);
}

void loop() {
    int leftSpeed = stopSpeed; // these can be adjusted from 90to create a true stop
    int rightSpeed = stopSpeed;
    int b1 = 0;
    int b2 = 0;
    int encode;
    char last;
    while ((Serial.available() > 0) && (last != '\n')) {
        encode = Serial.parseInt();
        leftSpeed = Serial.parseInt();
        rightSpeed = Serial.parseInt();
        b1 = Serial.parseInt();
        b2 = Serial.parseInt();
        leftSpeed = map(leftSpeed, 0, 1023, 0, 180);
        rightSpeed = map(rightSpeed, 0, 1023, 180, 0);
        last = Serial.read();
    }
    if (encode == 20) {
        Lmotor.write(leftSpeed);
        Rmotor.write(rightSpeed);
        if(b1 == 1){
          Act1();
        }
        if(b2 == 1){
          Act2();
        }
        delay(50);
    }
    else {
        hacker();
    }
}

void Act1(){
  int x;
  x = 1;
}

void Act2(){
  int y;
  y = 1;
}

void hacker(){
  while (1 == 1){
    Lmotor.write(stopSpeed);
    Rmotor.write(stopSpeed);
  }
}


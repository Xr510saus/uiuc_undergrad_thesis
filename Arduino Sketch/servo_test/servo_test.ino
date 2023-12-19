#include <Servo.h>

Servo s1;
Servo s2;
int servo1_pin = 3;
int servo2_pin = 5;
int pos1 = 0;
int pos2 = 0;

int pmin = 5;
int pmax = 90;

void setup() {
  s1.attach(servo1_pin);
  s2.attach(servo2_pin);
  // s1.write(90);
}

void loop() {
  if (s1.read() != pmin || s2.read() != pmin) {
    for (pos1 = s1.read(); pos1 >= pmin; pos1 -= 5) {
      s1.write(pos1);
      s2.write(pos1);
      delay(15);
    }
    delay(500);
  }
  // if (s2.read() != pmin) {
  //   for (pos2 = s2.read(); pos2 >= pmin; pos2 -= 5) {
  //     s2.write(pos2);
  //     delay(15);
  //   }
  //   delay(500);
  // }
  
  for (pos1 = pmin; pos1 <= pmax; pos1 += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    s1.write(pos1);              // tell servo to go to position in variable 'pos'
    s2.write(pos1);
    delay(15); // delay to allow the servo to reach the desired position
    // if (pos==90){
    //   delay(1000); //wait 5 seconds once positioned at 90 degrees
    // }
  }
  delay(500); // wait 5 seconds after reaching 180 degrees
 
  for (pos1 = pmax; pos1 >= pmin; pos1 -= 5) { // goes from 180 degrees to 0 degrees
    s1.write(pos1);              // tell servo to go to position in variable 'pos'
    s2.write(pos1);
    delay(15);
    // if (pos==90){
    //   delay(1000); // wait 5 seconds once positioned at 90 degrees
    // }
  }
  delay(500); // wait 5 seconds after arriving back at 0 degrees
}

// void setup() {

// }

// void loop() {

// }
#include <NewPing.h>
int trigger = 5;
int echo = 2;
int led = 11;
int left_motor = 10;
int right_motor = 9;
int button = 13;
int times[] = {3000, 4000, 5000};
int distance[] = {30, 10, 5};
bool checker = true;
NewPing sonar(trigger, echo, 200);
int range;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(left_motor, OUTPUT);
  pinMode(right_motor, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  // sets initial motors to 0
  analogWrite(left_motor, 0);
  analogWrite(right_motor, 0);
}
//http://forum.arduino.cc/index.php?topic=45787.0
void loop() {
  //  if (digitalRead(button) == 1) {
  //    starter += 1;
  //  }

  // while (starter >= 1 ) {
  if (checker == true) {
      analogWrite(left_motor, 0);
      analogWrite(right_motor, 255);
      delay(6000);
  }
  checker = false;
  range = sonar.ping_cm();
  Serial.println(range);
  delay(50);
  if (range == distance[0]) {
    analogWrite(left_motor, 255);
    analogWrite(right_motor, 255);
  }
  else if (range > distance[0]) {
    analogWrite(right_motor, 127);
    analogWrite(left_motor, 190);
  }
  else if (range < distance[0]) {
    analogWrite(left_motor, 80);
    analogWrite(right_motor, 255);
  }
  //}
}

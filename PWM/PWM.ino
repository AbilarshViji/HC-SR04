#include <NewPing.h>
int trigger = 4;
int echo = 3;
int led = 11;
int left_motor = 10;
int right_motor = 9;
int button = 8;
int times[] = {3000, 4000, 5000};
int distance[] = {30, 10, 5};
double pingpong = 0;
NewPing sonar(trigger, echo, 150);
double range;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(left_motor, OUTPUT);
  pinMode(right_motor, OUTPUT);

  pinMode(button, INPUT);
  Serial.begin(9600);
}
//http://forum.arduino.cc/index.php?topic=45787.0
void loop() {
  // if (button == HIGH) {
  //delay(50);
  //range = sonar.ping_cm();
  //Serial.println(range);
  pingpong = 0;
  for (int i = 0; i <= 24; i++) {
    pingpong += sonar.ping();
    delay(10);
  }
  range = pingpong / 25 / 58.2;
  Serial.println(range);
  //   while ((endtime - starttime) <= times[1]) //wont work
  if (range == distance[0]) {
    analogWrite(left_motor, 255);
    analogWrite(right_motor, 255);
  }
  else if (range > distance[0]) {
    analogWrite(right_motor, 150);
    analogWrite(left_motor, 190);

  }
  else if (range < distance[0]) {
    analogWrite(left_motor, 80);
    analogWrite(right_motor, 255);

  }


  //  }
}


#include <NewPing.h>
int trigger = 4;
int echo = 3;
int left_motor = 10;
int right_motor = 9;
int button = 13;
int timer[] = {3000, 2000, 2500};
int distance[] = {30, 20, 15};
bool starter;
NewPing sonar(trigger, echo, 200);
int range;
void setup() {
  // put your setup code here, to run once:
  pinMode(left_motor, OUTPUT);
  pinMode(right_motor, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  // sets initial motors to 0
  analogWrite(left_motor, 0);
  analogWrite(right_motor, 0);
}
void abitech(int timer, int distance) {
  range = sonar.ping_cm();
  Serial.println(range);
  int starttime;
  int endtime;
  starttime = millis();
  endtime = starttime;
  while ((endtime - starttime) <= timer) {
    if (range == distance) {
      analogWrite(left_motor, 255);
      analogWrite(right_motor, 255);
    }
    else if (range > distance) {
      analogWrite(right_motor, 127);
      analogWrite(left_motor, 190);
    }
    else if (range < distance) {
      analogWrite(left_motor, 80);
      analogWrite(right_motor, 255);
    }
  }
}
void loop() {
  //  Serial.println(starter);

  if (digitalRead(button) == 1) {
    starter += 1;
  }
  while (starter >= 1 ) {
    for (int i = 0; i < 3; i++) {
      abitech(distance[i], timer[i]);
    }
    starter = 0;
  }
}

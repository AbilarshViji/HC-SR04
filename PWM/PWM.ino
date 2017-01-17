#include <NewPing.h>
#include <SimpleTimer.h>

int trigger = 4;
int echo = 3;
int left_motor = 10;
int right_motor = 9;
int button = 13;
int starter = 0;
int range;
NewPing sonar(trigger, echo, 200);
SimpleTimer timer;

void setup() {

  pinMode(left_motor, OUTPUT);
  pinMode(right_motor, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  // sets initial motors to 0
  analogWrite(left_motor, 0);
  analogWrite(right_motor, 0);
}

void circle() {
  analogWrite(left_motor, 0);
  analogWrite(right_motor, 255);
  delay(4000);
}

void abitech(int distance) {
  range = sonar.ping_cm();
  Serial.println(range);
  if (range == distance) {
    analogWrite(left_motor, 255);
    analogWrite(right_motor, 255);
    timer.setTimeout(2000, circle);
    timer.run();
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

void loop() {
  if (digitalRead(button) == 1) {
    starter += 1;
  }
  while (starter >= 1 ) {
    abitech(20);
  }
}

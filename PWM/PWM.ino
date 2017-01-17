#include <NewPing.h>
#include "MillisTimer.h"

int trigger = 4;
int echo = 3;
int left_motor = 10;
int right_motor = 9;
int button = 13;
int range;
NewPing sonar(trigger, echo, 200);
MillisTimer timer1 = MillisTimer(1000);


void setup() {
  timer1.setInterval(1000);
  timer1.setRepeats(1);
  timer1.start();
  pinMode(left_motor, OUTPUT);
  pinMode(right_motor, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  // sets initial motors to 0
  analogWrite(left_motor, 0);
  analogWrite(right_motor, 0);
}
void abitech(int distance) {
  range = sonar.ping_cm();
  Serial.println(range);
    if (range == distance) {
      analogWrite(left_motor, 255);
      analogWrite(right_motor, 255);
timer1.run();
      }
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

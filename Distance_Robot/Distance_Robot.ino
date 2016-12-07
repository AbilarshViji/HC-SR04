#include <NewPing.h>
int trigger = 13;
int echo = 12;
int led = 11;
int left_motor = 10;
int right_motor = 9;
int button = 8;
int times[] = {3000, 4000, 5000};
int distance[] = {10, 20, 5};
int count = 0;
const int checker = 5;
long starttime;
long endtime;
int range;
int section = 0;
NewPing sonar(trigger, echo,5000);
void setup() {
  pinMode(led, OUTPUT);
  pinMode(left_motor, OUTPUT);
  pinMode(right_motor, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}
//http://forum.arduino.cc/index.php?topic=45787.0
void loop() {
  beginning:
  if (button == HIGH) {
    section = 1;
    while (true) {
      delay(50);
      range = sonar.ping_cm();
      Serial.println(range);
    }
    switch (section) {
      case 1:
        if (range == distance[1]) {
          digitalWrite(left_motor, HIGH);
          digitalWrite(right_motor, HIGH);
          count += 1;
          if (count = checker) {
            delay(times[1]);
            count = 0;
            section = 2;
            break;
          }
        }
        else if (range > distance[1]) {
          digitalWrite(right_motor, HIGH);
          count = 0;
        }
        else if (range < distance[1]) {
          digitalWrite(left_motor, HIGH);
          count = 0;
        }
      case 2:
        if (range == distance[2]) {
          digitalWrite(left_motor, HIGH);
          digitalWrite(right_motor, HIGH);
          count += 1;
          if (count = checker) {
            delay(times[2]);
            count = 0;
            section = 3;
            break;
          }
        }
        else if (range > distance[2]) {
          digitalWrite(right_motor, HIGH);
          count = 0;
        }
        else if (range < distance[2]) {
          digitalWrite(left_motor, HIGH);
          count = 0;
        }
      case 3:
        if (range == distance[3]) {
          digitalWrite(left_motor, HIGH);
          digitalWrite(right_motor, HIGH);
          count += 1;
          if (count = checker) {
            delay(times[3]);
            count = 0;
            section = 0;
            break;
          }
        }
        else if (range > distance[3]) {
          digitalWrite(right_motor, HIGH);
          count = 0;
        }
        else if (range < distance[3]) {
          digitalWrite(left_motor, HIGH);
          count = 0;
        }
        default:
        goto beginning;
    }
  }
}

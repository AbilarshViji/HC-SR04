#include <NewPing.h>
int trigger = 13;
int echo = 12;
int led = 11;
int left_motor = 10;
int right_motor = 9;
int button = 8;
int times[] = {3000, 4000, 5000};
int distance[] = {10, 20, 5};
long starttime;
long endtime;
NewPing sonar(trigger, echo);
int range;
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
  // put your main code here, to run repeatedly:
 // if (button == HIGH) {
    while (true) {
      delay(50);
      range = sonar.ping_cm();
      Serial.println(range);
    }
    starttime = millis();
    endtime = starttime;
 //   while ((endtime - starttime) <= times[1]) //wont work
      if (range == distance[1]) {
        digitalWrite(left_motor, HIGH);
        digitalWrite(right_motor, HIGH);
      }
      else if (range > distance[1]) {
        digitalWrite(right_motor, HIGH);

      }
      else if(range < distance[1]) {
        digitalWrite(left_motor, HIGH);

      }
    

 // }
}

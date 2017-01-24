#include <NewPing.h>
int trigger = 5;
int echo = 2;
int range;
NewPing sonar(trigger, echo, 200);

void setup() {
  Serial.begin(9600);
}

void loop() {
  range = sonar.ping_cm();
  delay(50);
  Serial.println(range);
}

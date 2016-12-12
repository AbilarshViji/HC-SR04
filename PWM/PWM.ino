  #include <NewPing.h>
int trigger = 13;
int echo = 12;
int led = 11;
int left_motor = 10;
int right_motor = 9;
int button = 8;
int times[] = {3000, 4000, 5000};
int distance[] = {20, 10, 5};
long starttime;
long endtime;
NewPing sonar(trigger, echo,150);
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
 // if (button == HIGH) {
      delay(50);
      range = sonar.ping_cm();
      Serial.println(range);
 //   while ((endtime - starttime) <= times[1]) //wont work
      if (range == distance[0]) {
        digitalWrite(left_motor, 250);
        digitalWrite(right_motor, 255);
      }
      else if (range > distance[0]) {
        analogWrite(right_motor, 110);
        analogWrite(left_motor, 220);

      }
      else if(range < distance[0]) {
        analogWrite(left_motor, 110);
        analogWrite(right_motor, 255);

      }


 // }
}


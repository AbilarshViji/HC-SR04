void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT); r back
pinMode(9,OUTPUT); l fwd
pinMode(7,OUTPUT); r fwd
pinMode(6,OUTPUT); l back

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10,HIGH);
digitalWrite(6,LOW);
delay(5000);
digitalWrite(10,LOW);
digitalWrite(9,HIGH);
delay(5000);
digitalWrite(7,HIGH);
digitalWrite(9,LOW);
delay(5000);
digitalWrite(6,HIGH);
digitalWrite(7,LOW);
delay(5000);
}

/*
HC-SR04 Ping distance sensor
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 9 Trig to Arduino pin 8
Buzzer +ve to Arduino pin 2 and GND to GND
DPST switch is used to choose between one among the two sensors
and LED lights helps us to indicate which sensor is active
*/

#define trigPin 8
#define echoPin 9
#define Buzzer 2

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(Buzzer, OUTPUT);

}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance < 100)
{
digitalWrite(Buzzer,HIGH); //less than 100cm then buzzer will produce beep sound

}
else {
digitalWrite(Buzzer,LOW);
}

if (distance >= 300 || distance <= 0)
{
Serial.println("Out of range");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(500);

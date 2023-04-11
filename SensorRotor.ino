/*
Created by: Andi Cucka
Created on: Apr 2023
Uses a distance sensor to check if the distance is less than 20cm.
*/

#include <Servo.h>


const int TRIG_PIN = 4;
const int ECHO_PIN = 3;

Servo servo;
int angle = 10;

float duration, distance;

void setup() {
servo.attach(2);
servo.write(angle);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

duration = pulseIn(ECHO_PIN, HIGH);
distance = (duration*.0343)/2;
Serial.print("Distance: ");
Serial.println(distance);
delay(100);
 if (distance < 20) { // Checks if the distance is less than 20cm
erial.print(distance);
Serial.println(" cm");
servo.write(90);
}
 else if (distance > 20) { // Checks if the distance is greater than 20cm
Serial.print(distance);
Serial.println(" cm");
servo.write(10);
}
}

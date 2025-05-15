#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

const int trigPin = D0;
const int echoPin = D5;

Servo myServo;
const int servoPin = D4;

const int SensorJarak = 15;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.println("Sistem palang otomatis siap...");
}

void loop() {
  long durasi, jarak;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  if (jarak > 0 && jarak <= SensorJarak) {

    myServo.write(90);
    delay(2000);
  } else {
    myServo.write(0);
  }
  delay(500);
}
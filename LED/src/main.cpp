#include <Arduino.h>

int LED1 = D0;
int LED2 = D6;
int LED3 = D7;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(3000);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(5000);
  digitalWrite(LED3, LOW);
}


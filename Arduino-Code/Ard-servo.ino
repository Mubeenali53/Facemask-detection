#include <Servo.h>

Servo myservo;
const int ledPin = 13; // Pin number for the onboard LED

void setup() {
  myservo.attach(9);
  Serial.begin(9600); // Initialize serial communication
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  if (Serial.available() > 0) {
    char receivedChar = Serial.read(); // Read a character from serial communication

    if (receivedChar == '1') {
      myservo.write(0);
      digitalWrite(ledPin, LOW); // Turn on the LED
    } else if (receivedChar == '0') {
      myservo.write(90);
      digitalWrite(ledPin, HIGH); // Turn off the LED
    }
  }
}

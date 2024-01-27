#include <Arduino.h>

// Pin number for the LED
const int ledPin = 12;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  
  // Wait for 1 second
  delay(1000);
  
  // Turn off the LED
  digitalWrite(ledPin, LOW);
  
  // Wait for 1 second
  delay(1000);
}
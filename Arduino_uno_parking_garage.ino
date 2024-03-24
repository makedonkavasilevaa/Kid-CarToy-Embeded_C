#include <Ultrasonic.h>

// Ultrasonic ultrasonic(6, 5); // 6 trig, 5 echo

int trigPin = 6;    // TRIG pin
int echoPin = 5;    // ECHO pin

float duration_us, distance_cm;
unsigned long startTime;

const int buzzer = 7; // pin buzzer

void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm < 5) {
    if (millis() - startTime < 5000) {
      // Beep for 2 seconds
      tone(buzzer, 1000);
    } else {
      // Stop the buzzer after 2 seconds
      noTone(buzzer);
    }
  } else if (distance_cm < 10) {
    tone(buzzer, 1000);
    delay(40);
    noTone(buzzer);
  } else if (distance_cm < 20) {
    tone(buzzer, 1000);
    delay(70);
    noTone(buzzer);
  } else {
    tone(buzzer, 0);
    noTone(buzzer);
    startTime = millis(); // Reset the start time when distance is not less than 5
  }

  delay(100); // Delay between measurements
}
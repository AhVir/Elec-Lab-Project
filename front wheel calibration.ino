#include <L293D.h>

// Define motor control pins
const int motorPin1 = 25;  // IN1 on motor driver
const int motorPin2 = 26;  // IN2 on motor driver
const int enablePin = 5;   // PWM enable pin for motor speed control

// L293D motor(enablePin, motorPin1, motorPin2);
L293D motor(2, 27, 13); // Define the left motor
L293D motorRight(enablePin, motorPin1, motorPin2); // Define the right motor

void setup() {
  Serial.begin(115200); // For debugging
}

void stop(int E_PIN, int pin1, int pin2) {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(E_PIN, LOW);
  Serial.println("Motor stopped!");
}

float baseSpeedLeft = -0.50;  // Left motor speed
float baseSpeedRight = 0.50;  // Right motor base speed
float speedIncrement = 0.6;  // Small increment for the right motor
int totalTime = 2500;         // Total time to move (in ms)
int stepDelay = 250;          // Delay between each speed increment (in ms)

void loop() {
  int steps = totalTime / stepDelay; // Calculate the number of steps
  for (int i = 0; i < steps; i++) {
    // Gradually increase the speed of the right motor
    motor.set(baseSpeedLeft);
    motorRight.set(baseSpeedRight + (speedIncrement * i));
    
    Serial.print("Left motor speed: ");
    Serial.print(baseSpeedLeft);
    Serial.print(" | Right motor speed: ");
    Serial.println(baseSpeedRight + (speedIncrement * i));
    
    delay(stepDelay); // Wait for a short time before adjusting speed again
  }

  // Stop both motors after moving using the stop function
  stop(2, 13, 27); // Stop the left motor
  stop(enablePin, motorPin1, motorPin2); // Stop the right motor
  delay(5000); // Wait 5 seconds before running again
}

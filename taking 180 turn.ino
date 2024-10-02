#include <L293D.h>

// Define motor control pins
const int motorPin1 = 25;  // IN1 on motor driver
const int motorPin2 = 26;  // IN2 on motor driver
const int enablePin = 5;   // PWM enable pin for motor speed control

// L293D motor(enablePin, motorPin1, motorPin2);
L293D motor(2, 27, 13); // Define the second motor
L293D motorRight(enablePin, motorPin1, motorPin2);

void setup() {
  Serial.begin(115200); // For debugging
}

void stop(int E_PIN, int pin1, int pin2){
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(E_PIN, LOW);
}

void loop() {
  // Nothing in the loop since we just want to run the motors once
  // Set motor speed and direction with a double value between -1 and 1
  motor.set(-.99); // 75% power forward
  motorRight.set(.99);
  delay(1000);

  stop(2, 13, 27);
  stop(enablePin, motorPin1, motorPin2);
  delay(1000);


  motor.set(.99); // 75% power forward
  motorRight.set(+.99);
  delay(1000);

  stop(2, 13, 27);
  stop(enablePin, motorPin1, motorPin2);
  delay(1000);

  // Use motor.get() to get current speed and then update it from that
  // motor.set(-255);
  // motorRight.set(-255);
  // while(motor.get() != 255)
  // {
  //   motor.set(motor.get() + 5); // Increment motor speed from previous speed
  //   motorRight.set(motorRight.get() + 5);
  //   delay(100); // Delay 100ms to see the speed changing
  // }
}

// void moveMotors(float speed, int duration) {
//   // Set motor speed and direction with a double value between -1 and 1
//   motor.set(speed);      // Move the left motor forward
//   motorRight.set(speed); // Move the right motor forward
  
//   delay(duration); // Keep the motors running for the specified duration

//   // Stop the motors after the duration
//   motor.set(0);
//   motorRight.set(0);
  
//   Serial.print("Motors ran at speed: ");
//   Serial.print(speed);
//   Serial.print(" for duration: ");
//   Serial.print(duration);
//   Serial.println(" ms.");
// }

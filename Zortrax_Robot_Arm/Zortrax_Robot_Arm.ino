/*
  Project: Robotic Arm Control
  Authors: Marouane LAMZIRAI, Achraf NORE-EDDINE, Oussama LAAYATI
  YouTube Channel: T-Win Technologies

  Description:
  This Arduino code controls a robotic arm using joystick inputs. The robotic arm has six stepper motors
  (X, Y, Z, E, Q, Gripper) and is designed for precise movements. Additionally, a fan is controlled to maintain
  optimal operating temperature.

  Pins Configuration:
  - X, Y, Z, E, Q Stepper Motors: Step, Direction, Enable pins
  - Gripper Stepper Motor: Step, Direction, Enable pins (Gripper is also connected to pin 1)
  - Joystick Inputs: joy1XPin, joy1YPin, joy2XPin, joy2YPin
  - Fan Control: fanPin
  - Limit Switch for Gripper: Gripper limitSwitch

  Note: Ensure proper wiring and connections for the motors, joystick, and other components.

  How to Use:
  - Connect the robotic arm components as per the defined pins.
  - Upload this code to your Arduino board.
  - Power on the system and use the joysticks to control the arm's movements.
  - Gripper movement is triggered by the limit switch on pin 1.
  - The fan is activated for temperature regulation.

  For a detailed demonstration, refer to the T-Win Technologies YouTube channel.
*/

#include <ezButton.h> // Include the ezButton library for handling the gripper limit switch

// Define Pin Configuration
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24

#define Q_STEP_PIN         36
#define Q_DIR_PIN          34
#define Q_ENABLE_PIN       30

#define Gripper            1

#define joy1XPin           A3
#define joy1YPin           A4
#define joy2XPin           A5
#define joy2YPin           A10

#define fanPin             A11     

ezButton limitSwitch(Gripper); // Initialize the gripper limit switch using the ezButton library

int Speed = 5; // Set the initial speed of the robotic arm movements

void setup() {
  // Configure Pins as OUTPUT
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);

  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);

  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);

  pinMode(E_STEP_PIN, OUTPUT);
  pinMode(E_DIR_PIN, OUTPUT);
  pinMode(E_ENABLE_PIN, OUTPUT);

  pinMode(Q_STEP_PIN, OUTPUT);
  pinMode(Q_DIR_PIN, OUTPUT);
  pinMode(Q_ENABLE_PIN, OUTPUT);

  // Disable all motor drivers initially
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  digitalWrite(E_ENABLE_PIN, LOW);
  digitalWrite(Q_ENABLE_PIN, LOW);
  
  // Configure Joystick and Fan Pins
  pinMode(joy1XPin, INPUT);
  pinMode(joy1YPin, INPUT);

  pinMode(joy2XPin, INPUT);
  pinMode(joy2YPin, INPUT);

  pinMode(fanPin, OUTPUT);

  // Begin Serial Communication
  Serial.begin(9600);
}

void loop() {
  // Start Fan
  analogWrite(fanPin, 254);

  // Joystick Control for Robotic Arm

  // Base Control
  while (map(analogRead(joy1XPin), 0, 1023, -100, 100) > 10) {
    
    digitalWrite(X_DIR_PIN, HIGH);
    for (int j = 0; j < 200; ++j) {
      digitalWrite(X_STEP_PIN, HIGH);
      delay(Speed);  
      digitalWrite(X_STEP_PIN, LOW);
      delay(Speed);  
      if (map(analogRead(joy1XPin), 0, 1023, -100, 100) < 10) {
        break;
      }
    }
  }

  while (map(analogRead(joy1XPin), 0, 1023, -100, 100) < - 10) {
    
      digitalWrite(X_DIR_PIN, LOW);  // Set opposite direction
      for (int j = 0; j < 200; ++j) {
        digitalWrite(X_STEP_PIN, HIGH);
        delay(Speed);  
        digitalWrite(X_STEP_PIN, LOW);
        delay(Speed);  
        if (map(analogRead(joy1XPin), 0, 1023, -100, 100) > -10) {
        break;
      }
      }
    }

  // Axis 1 Control
  while (map(analogRead(joy1YPin), 0, 1023, -100, 100) < - 10) {
    
    digitalWrite(Y_DIR_PIN, LOW);
    for (int j = 0; j < 200; ++j) {
      digitalWrite(Y_STEP_PIN, HIGH);
      delay(Speed);  
      digitalWrite(Y_STEP_PIN, LOW);
      delay(Speed);  
      if (map(analogRead(joy1YPin), 0, 1023, -100, 100) > -10) {
        break;
      }
    }
  }

  while (map(analogRead(joy1YPin), 0, 1023, -100, 100) > 10) {
    
    digitalWrite(Y_DIR_PIN, HIGH);
    for (int j = 0; j < 200; ++j) {
      digitalWrite(Y_STEP_PIN, HIGH);
      delay(Speed);  
      digitalWrite(Y_STEP_PIN, LOW);
      delay(Speed);  
      if (map(analogRead(joy1YPin), 0, 1023, -100, 100) < 10) {
        break;
      }
    }
  }

  // Axis 2 Control
  while (map(analogRead(joy2XPin), 0, 1023, -100, 100) > 10) {
    
    digitalWrite(E_DIR_PIN, HIGH);
    for (int j = 0; j < 200; ++j) {
      digitalWrite(E_STEP_PIN, HIGH);
      delay(Speed);  
      digitalWrite(E_STEP_PIN, LOW);
      delay(Speed);  
      if (map(analogRead(joy2XPin), 0, 1023, -100, 100) < 10) {
        break;
      }
    }
  }

  while (map(analogRead(joy2XPin), 0, 1023, -100, 100) < - 10) {
    
      digitalWrite(E_DIR_PIN, LOW);  // Set opposite direction
      for (int j = 0; j < 200; ++j) {
        digitalWrite(E_STEP_PIN, HIGH);
        delay(Speed);  
        digitalWrite(E_STEP_PIN, LOW);
        delay(Speed);  
        if (map(analogRead(joy2XPin), 0, 1023, -100, 100) > -10) {
          break;
        }
      }
    }

  // Axis 3 Control
  while (map(analogRead(joy2YPin), 0, 1023, -100, 100) < - 10) {
    
    digitalWrite(Z_DIR_PIN, LOW);
    for (int j = 0; j < 200; ++j) {
      digitalWrite(Z_STEP_PIN, HIGH);
      delay(Speed);  
      digitalWrite(Z_STEP_PIN, LOW);
      delay(Speed);  
      if (map(analogRead(joy2YPin), 0, 1023, -100, 100) > -10) {
        break;
      }
    }
  }

  while (map(analogRead(joy2YPin), 0, 1023, -100, 100) > 10) {
    
    digitalWrite(Z_DIR_PIN, HIGH);
    for (int j = 0; j < 200; ++j) {
      digitalWrite(Z_STEP_PIN, HIGH);
      delay(Speed);  
      digitalWrite(Z_STEP_PIN, LOW);
      delay(Speed);  
      if (map(analogRead(joy2YPin), 0, 1023, -100, 100) < 10) {
        break;
      }
    }
  }
}

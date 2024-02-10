# Robotic Arm Control

![Robotic Arm](robotic_arm_image.jpg)

## Overview

This project demonstrates the control of a robotic arm using an Arduino Mega and various components. The robotic arm is designed based on the Zortrax robot arm, with added extensions, a fourth axis, gripper control, joysticks for manual operation, and a control box containing a fan, ramps 1.4 board, and Arduino Mega.

## Features

- **Six-Axis Control:** Precise control of X, Y, Z, E, Q, and Gripper axes.
- **Joystick Operation:** Manual control using joysticks for fluid movements.
- **Gripper Control:** Automated gripper control with a limit switch for precise positioning.
- **Fan Regulation:** Temperature control with a fan to maintain optimal operating conditions.
- **Extension Designs:** Added extensions for enhanced functionality.

## Components

- Arduino Mega
- Ramps 1.4 Board
- Joysticks for manual control
- Stepper motors for each axis (X, Y, Z, E, Q, Gripper)
- Limit switch for gripper
- Fan for temperature regulation

## Wiring

Ensure correct wiring of stepper motors, joysticks, gripper limit switch, and fan as per the defined pin configurations in the Arduino code.

## Usage

1. Connect the robotic arm components following the provided wiring instructions.
2. Upload the Arduino code to your Arduino Mega.
3. Power on the system.
4. Use the joysticks to control the arm's movements.
5. Gripper movement is triggered by the limit switch.
6. The fan is activated for temperature regulation.

## Demo

For a detailed demonstration and tutorial, check out the [T-Win Technologies YouTube channel](https://www.youtube.com/channel/YOUR_CHANNEL).

## Authors

- Marouane LAMZIRAI
- Achraf NORE-EDDINE

## Contributing

Contributions are welcome! Fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

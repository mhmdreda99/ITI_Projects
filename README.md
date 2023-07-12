
![Cover](https://github.com/mhmdreda99/ITI_Projects/blob/master/RC_CAR/RC.BMP)

# Mode Operated RC Car 

## Table of Contents
- [Mode Operated RC Car](#mode-operated-rc-car)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Features](#features)
  - [Hardware Requirements](#hardware-requirements)
  - [Software Requirements](#software-requirements)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Contributing](#contributing)
  - [License](#license)
  - [Credits](#credits)

## Overview
This RC Car is an Arduino-based project that enables an RC car to navigate through a maze autonomously. The car is equipped with various sensors and motor drivers to detect obstacles, follow lines, and navigate the maze efficiently.

## Features
- Bluetooth Control: The RC car can be controlled via Bluetooth using a mobile device or computer. It supports commands such as forward, backward, left turn, and right turn.
- Obstacle Avoidance: The car uses an ultrasonic sensor to detect obstacles in its path. When an obstacle is detected, the car stops, turns right to avoid the obstacle, and then continues moving forward.
- Line Following: The car incorporates line-following functionality using infrared (IR) sensors. It can detect and follow black lines on a white surface. It adjusts its movement based on the readings from the IR sensors to stay on the line.
- Maze Navigation: The RC car is capable of autonomously navigating through a maze. It uses a predefined maze layout and employs a simple algorithm to make decisions at each intersection or turn. It follows a path until it reaches the goal.

## Hardware Requirements
To build and run the RC Car Maze Solver, you will need the following components:
- Arduino board (e.g., Arduino Uno)
- L298 motor driver module
- Ultrasonic sensor (HC-SR04)
- Infrared (IR) sensors (two for line following)
- RC car chassis with motors
- LCD display (compatible with LiquidCrystal library)
- Bluetooth module (e.g., HC-05)
- Push button

Refer to the circuit diagram for the appropriate connections between the components.

## Software Requirements
The project requires the Arduino IDE to upload the code to the Arduino board. The code is written in C++ and utilizes various libraries, including:
- LiquidCrystal: Used to control the LCD display.(Required)
- SoftwareSerial: Required for Bluetooth communication (if using a software serial connection). (optional)


## Installation
1. Connect the components as per the circuit diagram.
2. Install the Arduino IDE (if not already installed) and open it.
3. Create a new Arduino sketch and copy the provided code into the sketch.
4. Install any required libraries mentioned in the Software Requirements section.
5. Select the appropriate board and port from the Tools menu in the Arduino IDE.
6. Upload the code to the Arduino board.
7. Ensure the RC car is placed in the starting position of the maze.
8. Power on the RC car and monitor the LCD display for the current mode and status.

## Usage
- Bluetooth Control: Connect to the RC car's Bluetooth module from your mobile device or computer. Send commands (F, B, L, R) to control the car's movement.
- Obstacle Avoidance Mode: In this mode, the car uses the ultrasonic sensor to detect obstacles. It will automatically stop, turn right to avoid the obstacle, and continue moving forward.
- Line Follower Mode: The car uses the IR sensors to follow a black line on a white surface. It adjusts its movement to stay on the line.
- Maze Navigation Mode: The car navigates through the maze autonomously. It follows a predefined maze layout and makes decisions at intersections based on the available paths.
- Mode Switching: Press the button connected to the Arduino board to switch between different modes: Bluetooth control, obstacle avoidance, line follower, and maze navigation.

## Contributing
Contributions to the RC Car project are welcomed. If you have any improvements, bug fixes, or new features to propose, please submit a pull request.

## License
The RC Car project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute the code for personal and commercial purposes.

## Credits
The RC Car Maze Solver project is developed and maintained by mhmdreda99.

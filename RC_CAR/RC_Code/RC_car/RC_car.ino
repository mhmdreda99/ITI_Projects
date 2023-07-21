/******************************************************************************************/
/*                                                                                       
/* File Name   : RC_car.ino                                                            
/*                                                                                     
/* Created on  : Jul 9 , 2023                                                          
/*                                                                                   
/* Author      : Mohamed Reda Ibrahim                                                
/*                                                                                 
/* Version     : V03                                                              
/*                                                                               
/* Description : This RC Car is an Arduino-based project that enables an RC car to 
/*               navigate through a maze autonomously. The car is equipped with 
/*                various sensors and motor drivers to detect obstacles, 
/*                follow lines, and navigate the maze efficiently.                 
/* Layer       : APP                                                       
/***************************************************************************************/

 
#include <LiquidCrystal.h>

// ========================L298 motor driver pins===========================
const int in1 = 8;
const int in2 = 7;
const int in3 = 6;
const int in4 = 5;
//=============================================================================

// ========================LCD pins=========================================
LiquidCrystal lcd(10, 9, A2, A3, A4, A5);  // RS, E, D4, D5, D6, D7 pins
//=============================================================================

//SoftwareSerial bluetoothSerial(0, 1); // RX, TX pins for Bluetooth module
const int buttonPin = 3;  // Choose a suitable digital pin for the button

//============================ Mode Select Assign. ===========================

const char MODE_BLUETOOTH = '1';
const char MODE_OBSTACLE = '2';
const char MODE_LINEFOLLOWER = '3';
const char MODE_MAZE = '4';
//=============================================================================

char mode = MODE_BLUETOOTH;

const int trigPinForward = 2;  // Ultrasonic sensor trigger pin
const int echoPinForward = 4; // Ultrasonic sensor echo pin
const int trigPinSide = 11;  // Ultrasonic sensor trigger pin (side)
const int echoPinLeft = 12; // Ultrasonic sensor echo pin (left side)
const int echoPinRight = 13; // Ultrasonic sensor echo pin (right side)


const int L_S = A1;   // Analog pin for left IR sensor
const int R_S = A0;  // Analog pin for right IR sensor


//============================ Bluetooth commands===========================
const char Forward = 'F';
const char Backward = 'B';
const char LEFT = 'L';
const char RIGHT = 'R';
//=============================================================================
//============================ Maze Config. ===========================
// Maze dimensions
const int mazeWidth = 4;
const int mazeHeight = 4;
//=============================================================================
/*
'S' represents the starting point of the maze.
'G' represents the goal or target point of the maze.
'#' represents obstacles or walls in the maze.
' ' represents empty spaces or paths in the maze.
Here's how the maze looks visually:
S###       S: Starting point
  ##       G: Goal point
#  #       #: Obstacle/Wall
## #
###G
*/

//=============================================================================
char maze[mazeHeight][mazeWidth] = {
  {'S', '#', '#', '#'},
  {' ', ' ', '#', ' '},
  {'#', ' ', ' ', '#'},
  {'#', '#', 'G', '#'}
};

// define command as array of char. to solve Terminal App. issue 
char command[3];
int i=0;

/**
 * @brief Initializes the Arduino board and sets up the necessary configurations.
 * 
 * This function is called once at the beginning of the program.
 */

void setup()
{
  Serial.begin(9600);  ///< Initialize the serial communication at a baud rate of 9600.
  pinMode(trigPinForward, OUTPUT);  // Set the trigger pin as an output.
  pinMode(echoPinForward, INPUT);   // Set the echo pin as an input.
  pinMode(trigPinSide, OUTPUT);   // Set the trigger pin for side sensors as an output.
  pinMode(echoPinLeft, INPUT);    // Set the echo pin for left side sensor as an input.
  pinMode(echoPinRight, INPUT);   // Set the echo pin for right side sensor as an input.
  pinMode(in1, OUTPUT);      // Set in1 pin as an output.
  pinMode(in2, OUTPUT);      // Set in2 pin as an output.
  pinMode(in3, OUTPUT);      // Set in3 pin as an output.
  pinMode(in4, OUTPUT);      // Set in4 pin as an output.
  pinMode(buttonPin, INPUT_PULLUP);  ///< Set the button pin as an input with internal pull-up resistor.
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeMode, FALLING);  // Attach an interrupt to the button pin.
  lcd.begin(16, 2);   // Initialize the LCD display with 16 columns and 2 rows.
  lcd.print("Welcome");   //Initial mode display: Display the "Welcome" message on the LCD.
}


/**
 * @brief The main loop function that runs continuously.
 *
 * This function is called repeatedly after the setup() function.
 * It executes different code based on the selected mode.
 */
 
void loop()
{
  // Other code for different modes
  if (mode == MODE_BLUETOOTH)
  {
    lcd.setCursor(0, 1);  // Set the cursor position for mode display
    lcd.print("Mode: Bluetooth   "); // Print the current mode
    // Bluetooth control mode code
    if (Serial.available())
    {
       command[i]= Serial.read();
       if(command[i] == '\n')
       Serial.println("Hello");
       Serial.println("Done");
       i++;
       if(i==3)
          i=0;
      handleBluetoothCommand(command[0]);
    }
  }
  else if (mode == MODE_OBSTACLE)
  {
    lcd.setCursor(0, 1);
    lcd.print("Mode: Obstacle    ");
    avoidObstacles();
    // Obstacle avoidance mode code
  }
  else if (mode == MODE_LINEFOLLOWER)
  {
    lcd.setCursor(0, 1);
    lcd.print("Mode: LineFollower    ");
    LineFollowerFunc();
    // Obstacle avoidance mode code
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Mode: Maze        ");
    followMaze();
    // Maze navigation mode code
  }
}
/**
 * @brief Set the operating mode of the robot based on the provided command.
 *
 * This function sets the operating mode of the robot based on the command received. The following modes are supported:
 * - '1': Sets the mode to MODE_BLUETOOTH.
 * - '2': Sets the mode to MODE_OBSTACLE.
 * - '3': Sets the mode to MODE_LINEFOLLOWER.
 * - '4': Sets the mode to MODE_MAZE.
 *
 * If an invalid command is provided, the function does nothing or handles the error as needed.
 *
 * @param command The command indicating the desired operating mode. Valid commands are '1', '2', '3', or '4'.
 *
 * @note Make sure to define the different operating modes and initialize the mode variable appropriately before calling this function.
 *
 * @return void
 */
void setMode(char command) {

  switch (command) {
    case '1':
      mode = MODE_BLUETOOTH;
      break;
    case '2':
      mode = MODE_OBSTACLE;
      break;
    case '3':
      mode = MODE_LINEFOLLOWER;
      break;
    case '4':
      mode = MODE_MAZE;
      break;
    default:
      // Invalid command, do nothing or handle the error
      break;
  }
}
/**
 * @brief Change the operating mode of the robot.
 *
 * This function changes the operating mode of the robot based on the current mode. It cycles through three modes:
 * - MODE_BLUETOOTH: If the current mode is MODE_BLUETOOTH, it changes the mode to MODE_OBSTACLE.
 * - MODE_OBSTACLE: If the current mode is MODE_OBSTACLE, it changes the mode to MODE_LINEFOLLOWER.
 * - MODE_LINEFOLLOWER: If the current mode is MODE_LINEFOLLOWER, it changes the mode back to MODE_BLUETOOTH.
 *
 * @note Make sure to define the different operating modes and initialize the mode variable appropriately before calling this function.
 *
 * @return void
 */
void changeMode()
{
  //Serial.println("ISR");
  if (mode == MODE_BLUETOOTH)
    mode = MODE_OBSTACLE;
  else if (mode == MODE_OBSTACLE)
    mode = MODE_LINEFOLLOWER;
  else if (mode == MODE_LINEFOLLOWER)
    mode = MODE_MAZE;
  
  //Serial.println(mode);
}
/**
 * @brief Handle commands received from a Bluetooth device and perform the corresponding action.
 *
 * This function takes a character command received from a Bluetooth device and performs the appropriate action
 * based on the command. The following commands are supported:
 * - 'F' or 'f': Move the robot forward by calling the moveForward() function.
 * - 'B' or 'b': Move the robot backward by calling the moveBackward() function.
 * - 'L' or 'l': Turn the robot left by calling the turnLeft() function.
 * - 'R' or 'r': Turn the robot right by calling the turnRight() function.
 * - Any other character: Stop the motors by calling the stopMotors() function.
 *
 * @param Copy_command The character command received from the Bluetooth device.
 *
 * @note Make sure to initialize the Bluetooth connection and the necessary motor control functions before calling this function.
 *
 * @return void
 */

void handleBluetoothCommand(char Copy_command)
{
  switch (Copy_command)
  {
    case Forward:
      moveForward();
      break;
    case Backward:
      moveBackward();
      break;
    case LEFT:
      turnLeft();
      break;
    case RIGHT:
      turnRight();
      break;
    default:
      stopMotors();
      break;
  }
}

/**
 * @brief Move the robot forward and display the "Forward" direction on an LCD screen.
 *
 * This function sets the appropriate control pins (in1, in2, in3, in4) to control the motors
 * in a way that makes the robot move forward. It also updates the LCD screen to display the
 * "Forward" direction at the top left corner (0, 0).
 *
 * @note Make sure to initialize the LCD screen and set the control pins appropriately before calling this function.
 *
 * @return void
 */
void moveForward() {
  lcd.setCursor(0, 0);
  lcd.print("Dir: Forward    ");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
/**
 * @brief Move the robot backward and display the "Backward" direction on an LCD screen.
 *
 * This function sets the appropriate control pins (in1, in2, in3, in4) to control the motors
 * in a way that makes the robot move backward. It also updates the LCD screen to display the
 * "Backward" direction at the top left corner (0, 0).
 *
 * @note Make sure to initialize the LCD screen and set the control pins appropriately before calling this function.
 *
 * @return void
 */
void moveBackward() {
  lcd.setCursor(0, 0);
  lcd.print("Dir: Backword   ");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
/**
 * @brief Turn the robot left and display the "Left" direction on an LCD screen.
 *
 * This function sets the appropriate control pins (in1, in2, in3, in4) to control the motors
 * in a way that makes the robot turn left. It also updates the LCD screen to display the
 * "Left" direction at the top left corner (0, 0).
 *
 * @note Make sure to initialize the LCD screen and set the control pins appropriately before calling this function.
 *
 * @return void
 */
void turnLeft() {
  lcd.setCursor(0, 0);
  lcd.print("Dir: Left       ");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
/**
 * @brief Turn the robot right and display the "Right" direction on an LCD screen.
 *
 * This function sets the appropriate control pins (in1, in2, in3, in4) to control the motors
 * in a way that makes the robot turn right. It also updates the LCD screen to display the
 * "Right" direction at the top left corner (0, 0).
 *
 * @note Make sure to initialize the LCD screen and set the control pins appropriately before calling this function.
 *
 * @return void
 */
void turnRight() {
  lcd.setCursor(0, 0);
  lcd.print("Dir: Right      ");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

/**
 * @brief Stop the motors and display the "Stop" direction on an LCD screen.
 *
 * This function stops the motors by setting the appropriate control pins (in1, in2, in3, in4) to LOW.
 * It also updates the LCD screen to display the "Stop" direction at the top left corner (0, 0).
 *
 * @note Make sure to initialize the LCD screen and set the control pins appropriately before calling this function.
 *
 * @return void
 */
void stopMotors() {
  lcd.setCursor(0, 0);
  lcd.print("Dir: Stop       ");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

/**
 * @brief Avoid obstacles by measuring the distance using an ultrasonic sensor and taking appropriate actions.
 *
 * This function utilizes the `getDistanceForward()` function to measure the distance to an obstacle using an ultrasonic sensor.
 * If the measured distance is less than 20 centimeters, it stops the motors, delays for 100 milliseconds, and then turns
 * the robot to the right for another 100 milliseconds before resuming forward movement.
 * If the measured distance is 20 centimeters or more, it continues moving forward.
 *
 * @note Make sure to set the appropriate pins for the ultrasonic sensor before calling this function.
 *
 * @return void
 */
void avoidObstacles()
{
  float distance = getDistanceForward();

  if (distance < 20)
  {
    stopMotors();
    delay(100);
    turnRight();
    delay(100);
  }
  else
  {
    moveForward();
  }
}

/**
 * @brief Measure the distance using an ultrasonic sensor and calculate the distance in centimeters.
 *
 * This function triggers an ultrasonic sensor to send out a sound wave and measures the time it takes
 * for the sound wave to bounce back. Based on the measured duration, it calculates the distance to an
 * object in centimeters using the speed of sound.
 *
 * @note Make sure to set the `trigPin` and `echoPin` appropriately before calling this function.
 *
 * @return The distance to an object in centimeters.
 */
float getDistanceForward()
{
  digitalWrite(trigPinForward, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinForward, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinForward, LOW);

  long duration = pulseIn(echoPinForward, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}
/**
 * @brief Measure the distance using two side ultrasonic sensors and calculate the distance in centimeters.
 *
 * This function triggers two ultrasonic sensors, one on the left and one on the right, to send out sound waves and measures
 * the time it takes for the sound waves to bounce back. Based on the measured durations, it calculates the distance to an
 * object on each side in centimeters using the speed of sound.
 *
 * @note Make sure to set the `trigPinSide`, `echoPinLeft`, and `echoPinRight` appropriately before calling this function.
 *
 * @return The distance to an object on each side in centimeters. The return value is the average of the left and right distances.
 */

float getDistanceSide()
{
  digitalWrite(trigPinSide, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinSide, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSide, LOW);

  long durationLeft = pulseIn(echoPinLeft, HIGH);
  
  digitalWrite(trigPinSide, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinSide, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSide, LOW);

  long durationRight = pulseIn(echoPinRight, HIGH);
  
  // Calculate the average duration of both side sensors
  float averageDuration = (durationLeft + durationRight) / 2.0;

  float distance = averageDuration * 0.034 / 2;

  return distance;
}


/**
 * @brief Follows the maze and navigates through it using obstacle detection.
 *
 * This function is responsible for navigating the maze using obstacle detection through ultrasonic sensors.
 * It calculates the distances in front and on the sides of the robot using `getDistanceForward()` and `getDistanceSide()` functions,
 * and based on these distances, it determines the appropriate action to take.
 * 
 * If the robot is close to the goal ('G'), it stops the motors and finishes maze navigation.
 * If there are obstacles in front or on the sides (within 20 centimeters), it stops the motors, turns the robot to the right, and resumes the maze exploration.
 * If there are no obstacles in front or on the sides, it continues navigating the maze based on the robot's current position in the maze.
 *
 * @note Make sure to define the maze layout using the 'maze' array and initialize the necessary pins for ultrasonic sensors before calling this function.
 * 
 * @return void
 */
void followMaze()
{
  int currentRow, currentCol;
  getCurrentPosition(currentRow, currentCol);

  if (maze[currentRow][currentCol] == 'G')
  {
    stopMotors();
    return;
  }

  float distanceForward = getDistanceForward();
  float distanceSide = getDistanceSide();

  if (distanceForward < 20 || distanceSide < 20)
  {
    stopMotors();
    delay(100);
    turnRight();
    delay(100);
  }
  else
  {
    if (maze[currentRow][currentCol + 1] == ' ' || maze[currentRow][currentCol + 1] == 'G')
    {
      moveForward();
      delay(1000);
      updatePosition(currentRow, currentCol + 1);
    }
    else if (maze[currentRow + 1][currentCol] == ' ' || maze[currentRow + 1][currentCol] == 'G')
    {
      turnRight();
      delay(1000);
      moveForward();
      delay(1000);
      updatePosition(currentRow + 1, currentCol);
    }
    else if (maze[currentRow][currentCol - 1] == ' ' || maze[currentRow][currentCol - 1] == 'G')
    {
      turnRight();
      delay(1000);
      turnRight();
      delay(1000);
      moveForward();
      delay(1000);
      updatePosition(currentRow, currentCol - 1);
    }
    else if (maze[currentRow - 1][currentCol] == ' ' || maze[currentRow - 1][currentCol] == 'G')
    {
      turnLeft();
      delay(1000);
      moveForward();
      delay(1000);
      updatePosition(currentRow - 1, currentCol);
    }
  }
}



/**
 * @brief Line follower function that controls the movement of a robot based on sensor readings.
 *
 * This function reads the digital values of two sensors, R_S (Right Sensor) and L_S (Left Sensor),
 * and determines the appropriate action to take based on the sensor readings.
 *
 * The following conditions are checked:
 * - If both the Right Sensor and Left Sensor are at white color, it calls the moveForward() function.
 * - If the Right Sensor is black and the Left Sensor is white, it calls the turnRight() function.
 * - If the Right Sensor is white and the Left Sensor is black, it calls the turnLeft() function.
 * - If both the Right Sensor and Left Sensor are at black color, it calls the stopMotors() function.
 *
 * @return void
 */
void LineFollowerFunc()
{

  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0))
  {
    //if Right Sensor and Left Sensor are at White color then it will call forword function
    moveForward();
  }

  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) {
    //if Right Sensor is Black and Left Sensor is White then it will call turn Right function
    turnRight();
  }

  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) {
    //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
    turnLeft();
  }

  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) {
    //if Right Sensor and Left Sensor are at Black color then it will call Stop function
    stopMotors();
  }
}

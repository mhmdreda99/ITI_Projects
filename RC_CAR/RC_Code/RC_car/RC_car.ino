//#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
// L298 motor driver pins
const int enA = 9;
const int in1 = 8;
const int in2 = 7;
const int enB = 10;
const int in3 = 6;
const int in4 = 5;

LiquidCrystal lcd(12, 11, A2, A3, A4, A5);  // RS, E, D4, D5, D6, D7 pins


//SoftwareSerial bluetoothSerial(0, 1); // RX, TX pins for Bluetooth module
const int buttonPin = 3;  // Choose a suitable digital pin for the button

// Bluetooth commands
const char MODE_BLUETOOTH = '1';
const char MODE_OBSTACLE = '2';
const char MODE_LINEFOLLOWER = '3';
const char MODE_MAZE = '4';

char mode = MODE_BLUETOOTH;

const int trigPin = 2;  // Ultrasonic sensor trigger pin
const int echoPin = 4; // Ultrasonic sensor echo pin

const int L_S = A0;   // Analog pin for left IR sensor
const int R_S = A1;  // Analog pin for right IR sensor


// Bluetooth commands
const char Forward = 'F';
const char Backward = 'B';
const char LEFT = 'L';
const char RIGHT = 'R';

// Maze dimensions
const int mazeWidth = 4;
const int mazeHeight = 4;

char maze[mazeHeight][mazeWidth] = {
  {'S', '#', '#', '#'},
  {' ', ' ', '#', ' '},
  {'#', ' ', ' ', '#'},
  {'#', '#', 'G', '#'}
};

// Bluetooth variables
char command;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeMode, FALLING);
  lcd.begin(16, 2);  // Set the LCD dimensions (16 columns, 2 rows)
  lcd.print("Welcome");  // Initial mode display
}

void loop()
{
  /*if (digitalRead(buttonPin) == LOW)
    {
    // Button is pressed, change the mode
    changeMode();
    delay(200); // Add a small delay for button debounce
    }*/

  // Other code for different modes
  if (mode == MODE_BLUETOOTH)
  {
    lcd.setCursor(0, 1);  // Set the cursor position for mode display
    lcd.print("Mode: Bluetooth   "); // Print the current mode
    // Bluetooth control mode code
    //Serial.println("Blutooth");
    if (Serial.available())
    {
      char command = Serial.read();
      Serial.println("\nDone");
      handleBluetoothCommand(command);
    }
  }
  else if (mode == MODE_OBSTACLE)
  {
    lcd.setCursor(0, 1);
    lcd.print("Mode: Obstacle    ");
    //lcd.print("Obstacle");
    avoidObstacles();
    // Obstacle avoidance mode code
  }
  else if (mode == MODE_LINEFOLLOWER)
  {
    lcd.setCursor(0, 1);
    lcd.print("Mode: LineFollower    ");
    //lcd.print("Obstacle");
    LineFollowerFunc();
    // Obstacle avoidance mode code
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Mode: Maze        ");
    Serial.println("Maze");
    followMaze();
    // Maze navigation mode code
  }
}
void setMode(char command) {

  switch (command) {
    case MODE_BLUETOOTH:
    case MODE_OBSTACLE:
    case MODE_MAZE:
      mode = command;
      break;
    default:
      // Invalid command, do nothing or handle the error
      break;
  }
}

void changeMode()
{
  Serial.println("ISR");
  if (mode == MODE_BLUETOOTH)
    mode = MODE_OBSTACLE;
  else if (mode == MODE_OBSTACLE)
    mode = MODE_LINEFOLLOWER;
  else if (mode == MODE_LINEFOLLOWER)
    mode = MODE_BLUETOOTH;
  Serial.println(mode);
}

void handleBluetoothCommand(char command)
{
  switch (command)
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

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void avoidObstacles()
{
  float distance = getDistance();

  if (distance < 20)
  {
    stopMotors();
    delay(500);
    turnRight();
    delay(1000);
  }
  else
  {
    moveForward();
  }
}

float getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}
void updatePosition(int newRow, int newCol)
{
  int currentRow, currentCol;

  // Find the current position in the maze
  for (int row = 0; row < mazeHeight; row++)
  {
    for (int col = 0; col < mazeWidth; col++)
    {
      if (maze[row][col] == 'S')
      {
        currentRow = row;
        currentCol = col;
        break;
      }
    }
  }

  // Clear the previous position
  maze[currentRow][currentCol] = ' ';

  // Update the current position
  maze[newRow][newCol] = 'S';
}

void followMaze()
{
  int currentRow, currentCol;
  getCurrentPosition(currentRow, currentCol);

  if (maze[currentRow][currentCol] == 'G')
  {
    stopMotors();
    return;
  }

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


void getCurrentPosition(int &row, int &col)
{
  // Read the values from the left and right IR sensors
  int leftReading = 0;
  int rightReading = 0;
  
  // Determine the current position based on the sensor readings
  if (leftReading < 500 && rightReading > 500)
  {
    // We are on the left side of the line
    col = 0;
  }
  else if (leftReading > 500 && rightReading < 500)
  {
    // We are on the right side of the line
    col = 1;
  }
  else
  {
    // We are on the center of the line
    col = 2;
  }
}
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

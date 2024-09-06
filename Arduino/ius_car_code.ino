// Pin definitions for Motor A (Left side motors)
int enA = 9;   // Enable pin for Motor A (left side)
int in1 = 8;   // Input 1 for Motor A
int in2 = 7;   // Input 2 for Motor A

// Pin definitions for Motor B (Right side motors)
int enB = 10;  // Enable pin for Motor B (right side)
int in3 = 6;   // Input 1 for Motor B
int in4 = 5;   // Input 2 for Motor B

void setup() {
  // Set all the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  Serial.println("Moving Forward");
  moveForward();      // Move all motors forward
  delay(2000);        // Run for 2 seconds

  Serial.println("Moving Backward");
  moveBackward();     // Move all motors backward
  delay(2000);        // Run for 2 seconds

  Serial.println("Turning Left");
  turnLeft();         // Turn left
  delay(2000);        // Turn for 2 seconds

  Serial.println("Turning Right");
  turnRight();        // Turn right
  delay(2000);        // Turn for 2 seconds

  Serial.println("Motor stopped");
  stopMotors();       // Stop all motors
  delay(2000);        // Stop for 2 seconds
}

// Function to move all motors forward
void moveForward() {
  // Left motors (Motor A)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Right motors (Motor B)
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  // Set motor speeds
  analogWrite(enA, 255);  // Full speed
  analogWrite(enB, 255);  // Full speed
}

// Function to move all motors backward
void moveBackward() {
  // Left motors (Motor A)
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Right motors (Motor B)
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  // Set motor speeds
  analogWrite(enA, 255);  // Full speed
  analogWrite(enB, 255);  // Full speed
}

// Function to turn left (left side motors stop, right side motors move forward)
void turnLeft() {
  // Left motors (Motor A stop)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  // Right motors (Motor B move forward)
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  analogWrite(enB, 255);  // Full speed for right motors
}

// Function to turn right (right side motors stop, left side motors move forward)
void turnRight() {
  // Left motors (Motor A move forward)
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Right motors (Motor B stop)
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  analogWrite(enA, 255);  // Full speed for left motors
}

// Function to stop all motors
void stopMotors() {
  // Left motors (Motor A)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  // Right motors (Motor B)
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

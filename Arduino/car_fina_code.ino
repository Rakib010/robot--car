// Ultra sonic sensor
  const int trigPin = 4;
  const int echoPin = 3; 
  // defines variables
  long duration;
  int distance;  
  int safeDistance = 25;
  // led and photo registor
  const int ledPin = 12;
  const int lightPin = A0;
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

  // Setup LED and Photo registor 
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
  // setup for Distance
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  // Initialize Serial Monitor
  // Serial.begin(9600);
  moveForward();      // Move all motors forward
}

void loop() {

  // Ultasonic sensor
  int freeDistance = measuringDistance();
  if(freeDistance>safeDistance){
    // move forwarda
    // Main car functions
    // Serial.println("Moving Forward");
    moveForward();      // Move all motors forward
    delay(1000);        // Run for 2 seconds
  }else{
    // stop
    // Serial.println("Motor stopped");
    stopMotors();       // Stop all motors
    delay(2000);        // Stop for 2 seconds
    // move backowrd
    // Serial.println("Moving Backward");
    moveBackward();     // Move all motors backward
    delay(2000);        // Run for 2 seconds
    // stop 
    // turn left
    // Serial.println("Turning Left");
    turnLeft();         // Turn left
    delay(2000);        // Turn for 2 seconds
  }

  // Main car functions
  // Serial.println("Moving Forward");
  // moveForward();      // Move all motors forward
  // delay(2000);        // Run for 2 seconds

  // Serial.println("Moving Backward");
  // moveBackward();     // Move all motors backward
  // delay(2000);        // Run for 2 seconds

  // Serial.println("Turning Left");
  // turnLeft();         // Turn left
  // delay(2000);        // Turn for 2 seconds

  // Serial.println("Turning Right");
  // turnRight();        // Turn right
  // delay(2000);        // Turn for 2 seconds

  // Serial.println("Motor stopped");
  // stopMotors();       // Stop all motors
  // delay(2000);        // Stop for 2 seconds

  // Light function
  CheckLight();
}

// Function to mesaure destand
int measuringDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  // Serial.print("Distance: ");
  // Serial.println(distance);
  return distance;
}

// Function to control light
void CheckLight(){
    // Light control code - lightsensor and LED:
    int lightStatus = analogRead(lightPin);
    if(lightStatus<=300){
      digitalWrite(ledPin, HIGH);
      // Serial.println("Day light is low, Headlight ON");
    }else{
      digitalWrite(ledPin, LOW);
      // Serial.println("Day light is high, Headlight OFF");
    }
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
/*
 * Original Author: Shawn Hettiarachchi
 * Latest Date Modified: 09/09/26
 * Block X
 */

// Pin Constants

const int TOUCH_SENSOR_PIN = 2;

const int MOTOR_POWER_A = 3;

const int MOTOR_POWER_B = 11;

const int MOTOR_DIR_A = 12;

const int MOTOR_DIR_B = 13;

// Other Constants

const int MOVE_BACK_TIME = 5000;

const int TURN_TIME = 6000;

const int MOVE_FORWARD_TIME = 10000;

void setup() {
  
  Serial.begin(9600);  
  
  pinMode(TOUCH_SENSOR_PIN, INPUT);

  pinMode(MOTOR_POWER_A, OUTPUT);

  pinMode(MOTOR_POWER_B, OUTPUT);

  pinMode(MOTOR_DIR_A, OUTPUT);

  pinMode(MOTOR_DIR_B, OUTPUT);
  
}

void loop() {

  moveForward();
  
  int touchState = digitalRead(TOUCH_SENSOR_PIN);

  if (touchState == HIGH) {

    Serial.println("The Sensor is being touched.");

    moveBack();

    turnLeft90();

    moveForward();

    turnRight90();

    moveForward();
    
  } else if (touchState == LOW) {
    
    Serial.println("The Sensor is untouched.");

    moveForward();
    
  }

}

// Helper Functions

void moveBack() {

  // Moving the Chassis Backwards

  digitalWrite(MOTOR_POWER_A, HIGH);

  digitalWrite(MOTOR_POWER_B, HIGH);

  digitalWrite(MOTOR_DIR_A, HIGH);

  digitalWrite(MOTOR_DIR_B, LOW);

  delay(MOVE_BACK_TIME);
    
}

void turnLeft90() {

  // Turning the Chassis 90 Degrees

  digitalWrite(MOTOR_DIR_A, LOW);

  digitalWrite(MOTOR_POWER_A, HIGH);

  digitalWrite(MOTOR_DIR_B, LOW);

  digitalWrite(MOTOR_POWER_B, LOW);

  delay(TURN_TIME);
  
}

void moveForward() {

  // Moving the Chassis Forward

  digitalWrite(MOTOR_POWER_A, HIGH);

  digitalWrite(MOTOR_POWER_B, HIGH);

  digitalWrite(MOTOR_DIR_A, LOW);
  
  digitalWrite(MOTOR_DIR_B, LOW);
  
  delay(MOVE_FORWARD_TIME);
  
}

void turnRight90() {

  // Turning the Chassis 90 Degrees

  digitalWrite(MOTOR_DIR_A, LOW);

  digitalWrite(MOTOR_POWER_A, LOW);

  digitalWrite(MOTOR_DIR_B, LOW);

  digitalWrite(MOTOR_POWER_B, HIGH);

  delay(TURN_TIME);
  
}
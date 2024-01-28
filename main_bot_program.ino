int maxSpeedCount = 255;  // initilizing the max speed of ROVER as 255 which is maxnimum value.
int speedCount = 15;      // increases or decrease speed of ROVER by 15 units.
char serialData;

// Motor A pin initialization and connection. (LEFT)

int in1 = 8;
int in2 = 7;
int enableMotorA = 9;  // This is a PWM pin assigned to enable for motor A.

// Motor B pin initialization and connection.  (RIGHT)

int in3 = 2;
int in4 = 4;
int enableMotorB = 3;  // This is a PWM pin assigned to enable for motor B.

void setup() {
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enableMotorA, OUTPUT);
  pinMode(enableMotorB, OUTPUT);
}


//Controlling motor's speed.
void increaseSpeed() {
  if (maxSpeedCount < 255) {
    maxSpeedCount += speedCount;
  } else {
    maxSpeedCount = 255;
  }
  Serial.println("INCREASING SPEED OF ROVER.");
}

void decreaseSpeed() {
  if (maxSpeedCount > 255) {
    maxSpeedCount -= speedCount;
  } else {
    maxSpeedCount = 0;
  }
  Serial.println("DECREASING SPEED OF ROVER.");
}

//Controlling movement of BOT.
void moveForward() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("MOVING FORWARD.");
}

void moveBackward() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("MOVING BACKWARD.");
}

void moveLeft() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("LEFT TURN.");
}

void moveRight() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("RIGHT TURN.");
}

void sharLeftTurn() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("TAKING SHARP LEFT TURN.");
}
void sharpRightTurn() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("TAKING SHARP RIGHT TURN.");
}

void stopRover() {
  analogWrite(enableMotorA, maxSpeedCount);
  analogWrite(enableMotorB, maxSpeedCount);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("STOPPING THE ROVER.");
}

void loop() {
  if (Serial.available()) {
    serialData = Serial.read();

    //performing corresponding movements with respective to the serial input by user.

    if (serialData == 'w') {
      moveForward();
    } else if (serialData == 's') {
      moveBackward();
    } else if (serialData == 'a') {
      moveLeft();
    } else if (serialData == 'd') {
      moveRight();
    } else if (serialData == 'q') {
      sharLeftTurn();
    } else if (serialData == 'e') {
      sharpRightTurn();
    } else if (serialData == 'i') {
      increaseSpeed();
    }else if (serialData == 'D') {
      decreaseSpeed();
    }else{
      stopRover();
    }
  }
}
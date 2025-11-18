/*
 * Filename: Stepper_Motor
 * Function: stepper motor rotates
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
// connect stepper motor pins IN1, IN2, IN3 and IN4 to IO16, IO17, IO18 and IO19, respectively
const int outPorts[] = {16, 17, 18, 19};

void setup() {
  // Set the pin of the stepper motor drive board to output mode
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
}

void loop(){
  // The stepper motor rotates once
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  // The stepper motor rotates once in the other direction
  moveSteps(false, 32 * 64, 3);
  delay(1000);
}

//Recommendation: When the motor rotates accurately, the millisecond range is 3 to 20
void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // move one step
    delay(constrain(ms,3,20)); // control speed
  }
}

void moveOneStep(bool dir) {
  // Define a variable that uses four lows to represent the state of the port
  static byte out = 0x01;
  // Determine the shift direction according to the direction of rotation
  if (dir) {  // move left
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else {   // move right
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // Output signals to each port
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms){
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}
void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}


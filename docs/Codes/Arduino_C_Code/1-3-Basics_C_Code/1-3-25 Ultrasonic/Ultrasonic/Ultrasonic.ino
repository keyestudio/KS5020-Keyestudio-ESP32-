/*  
 * Filename: Ultrasonic
 * Function: detect distance with ultrasonic
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
// Define pins for the ultrasonic sensor
const int trigPin = 13;
const int echoPin = 12;

// Function prototype for reading sensor data
float readSensorData();

void setup() {
  // Begin serial communication at 115200 baud rate
  Serial.begin(9600);
  // Set echoPin as input and trigPin as output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Print sensor information to the serial monitor
  Serial.println("Ultrasonic sensor:");  
}

void loop() {
  // Read distance from the ultrasonic sensor
  float distance = readSensorData();
  // Print the measured distance to the serial monitor
  Serial.print("distance: ");
  Serial.print(distance);   
  Serial.println(" cm");
  // Delay between readings
  delay(100);
}

// Function to read data from the ultrasonic sensor
float readSensorData() {
  // Trigger a low signal before sending a high signal
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Send a 10-microsecond high signal to the trigPin
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  // Return to low signal
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the high signal on the echoPin
  unsigned long microsecond = pulseIn(echoPin, HIGH);

  // Calculate the distance using the speed of sound (29.00µs per centimeter)
  float distance = microsecond / 29.00 / 2;

  // Return the calculated distance
  return distance;
}
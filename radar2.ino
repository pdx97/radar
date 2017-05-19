// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(12); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 0 to 180 degrees
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(150);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

  Serial.print("angle :");
  Serial.println(i); // Sends the  degree into the Serial Port
  Serial.print("..."); //  addition character
  Serial.print("distance :"); // Sends the distance value into the Serial Port
  Serial.println(distance);
  Serial.print("..."); //  addition character 
  }
  // Repeats the previous lines from 180 to 0 degrees
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(150);
  distance = calculateDistance();
  
  Serial.print("angle :");
  Serial.println(i); // Sends the current degree into the Serial Port
  Serial.print("..."); // addition character
  Serial.print("distance :"); // Sends the distance value into the Serial Port
  Serial.println(distance);
  Serial.print("..."); // addition character 
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

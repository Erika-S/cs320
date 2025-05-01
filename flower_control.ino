#include <Servo.h> 

// Declare the Servo pin 
int servoPin = 9; 
Servo Servo1; 
bool productive = false;
bool defaultPosition = true;

void setup() { 
   // attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   Serial.begin(9600); // Initialize serial communication
}

void loop() {
  Serial.println(productive);
  Serial.println(defaultPosition);
  // if user is typing and flower is enclosed
  if (Serial.available() > 0 && defaultPosition == true) {
    while (Serial.available() > 0) {
        char incoming = Serial.read();  // Read and discard each byte in the buffer
        Serial.println(incoming);
    }
    // bloom the flower
    delay(1000);
    Serial.println("productive now");
    Servo1.write(105);  
    delay(500); 
    Servo1.detach();
    Servo1.attach(servoPin);
    defaultPosition = false;
    delay(1000); 
  }
  // else the user is not typing, retract the flower
  else if(!defaultPosition){
    delay(2000); 
    defaultPosition = true;
    Servo1.write(75);
    delay(500);
    Servo1.detach();
    Servo1.attach(servoPin);
    delay(1000); 
  }
}
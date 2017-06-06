#include <Servo.h>
Servo myservo;
#define SERVO_PIN 8

void setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(90);
}

void loop() {
  myservo.write(0); 
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(180);
  delay(1000);
  
}

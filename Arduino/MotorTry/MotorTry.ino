#include <NewPing.h>
#include <Servo.h> 

int distance = 100;
int motorPin = 11;
int motorPin2 = 12;
int selectedPin = motorPin;
#define TRIG_PIN A0 //A4 
#define ECHO_PIN A1 //A5 
#define MAX_DISTANCE 200 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;

void setup() {
   myservo.attach(2);  
   myservo.write(115);
   delay(2000);
   distance = readPing();
   delay(100);
   distance = readPing();
   delay(100);
   distance = readPing();
   delay(100);
   distance = readPing();
   delay(100);

   pinMode(motorPin, OUTPUT);
   pinMode(motorPin2, OUTPUT);
   Serial.begin(9600);
   while (! Serial);
   Serial.println("Speed 0 to 255");
}

void loop() {
   myservo.write(0);
   if (Serial.available()) {
      myservo.write(180);
      int speed = Serial.parseInt();
      if (speed >= 0 && speed <= 255) {
         analogWrite(selectedPin, speed);
      }
      if (speed == 256) {
         selectedPin = motorPin2;   
      } else if (speed == 257) {
        selectedPin = motorPin;  
      }
      delay(1000);
      int dis = readPing();
      Serial.print("Distance = " );
      Serial.println(dis);
      irSensor();
   }
}

void irSensor()
{
      int irSensorValue;
      irSensorValue=analogRead(4);   //connect proximity sensor to Analog 0
      Serial.print("IR Sensor value ");
      Serial.println(irSensorValue,DEC);// display analog values on serial port        
      delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

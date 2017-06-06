#include <NewPing.h>
#define ECHO_PIN A0
#define TRIG_PIN A1
#define MAX_DISTANCE 200 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
int distance = 0;
void setup() {
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Distance = ");
  delay(2000);
  distance = readPing();
  Serial.println(distance);
  delay(100);
  distance = readPing();
  Serial.println(distance);
  delay(100);
  distance = readPing();
  Serial.println(distance);
  delay(100);
  distance = readPing();
  Serial.println(distance);
  delay(100);
}

void loop() {
  delay(500);
  distance = readPing();
  Serial.println(distance);
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

//Left
const int motorPin1  = 4;  
const int motorPin2  = 5;  
//Right Motor B
const int motorPin3  = 11; 
const int motorPin4  = 12;  


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motorPin1, 200);
  analogWrite(motorPin2, 0);   
  analogWrite(motorPin3, 255);
  analogWrite(motorPin4, 0);   
  delay(300);
}

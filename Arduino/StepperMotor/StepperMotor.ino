const int motorPin1  = 9;  
const int motorPin2  = 10;  
//Motor B
const int motorPin3  = 11; 
const int motorPin4  = 12;  


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 180);   
  delay(300);
}

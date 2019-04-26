

#include <AFMotor.h> 
//#include <Servo.h>   
String voice;

//AF_DCMotor motor1 (1, MOTOR12_1KHZ); 
//AF_DCMotor motor2 (2, MOTOR12_1KHZ); 
//Servo myServo; 

AF_DCMotor motor1 (1); 
AF_DCMotor motor2 (2); 

void setup()
{
  Serial.begin(9600); 
  //myServo.attach(10); 
  //myServo.write(90);  

}

void loop() 
{
  while (Serial.available()){ 
     delay(10); 
    char c = Serial.read(); 
    if (c == '#') {break;} 
    voice += c; 
  }
  if (voice.length() > 0){
    Serial.println(voice);

    if(voice == "FF"){
      forward_car();
      }
    else if(voice == "BB"){
      back_car();
      }
    else if(voice == "RR") {
      right_car();
    }
    else if(voice == "LL") {
      left_car();
    }
    else if(voice == "SS") {
      stop_car();
    }
    
  voice=""; 
  }
}

void forward_car()
{    Serial.println("HI");

  motor1.run(BACKWARD);
  motor1.setSpeed(255);
  motor2.run(BACKWARD);
  motor2.setSpeed(255);
  //delay(2000);
  //motor1.run(RELEASE);
  //motor2.run(RELEASE);
}
  
void back_car()
{
  motor1.run(FORWARD);
  motor1.setSpeed(255);
  motor2.run(FORWARD);
  motor2.setSpeed(255);
  //delay(2000);
  //motor1.run(RELEASE);
  //motor2.run(RELEASE);
}
  
void right_car()
{
  //myServo.write(0);
  //delay(1000);
  //myServo.write(90);
  //delay(1000);
  motor2.run(BACKWARD);
  motor2.setSpeed(100);
  motor1.run(FORWARD);
  motor1.setSpeed(100);
   delay(400);
  motor1.run(RELEASE);
  motor2.run(RELEASE);

}
  
void left_car()
{
 // myServo.write(180);
  //delay(1000);
  //myServo.write(90);
  //delay(1000);
  motor2.run(FORWARD);
  motor2.setSpeed(100);
  motor1.run(BACKWARD);
  motor1.setSpeed(100);
  delay(400);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void stop_car ()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

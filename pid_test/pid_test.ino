/////////Ball and Plate///////////////////////////////
/*
BALL AND PLATE PID CONTROL
*/
//////////////////////////////////////////////////////
///Libraries///
#include <PID_v1.h>
#include <stdint.h>
#include "TouchScreen.h"
#include <SPI.h>
#include <Wire.h>
#include<Servo.h>

#include <math.h> 

// De finitions TOUCH PINS
#define XM A3  // must be an analog pin, use "An" notation!
#define YM A2   // can be a digital pin
#define XP A1   // can be a digital pin
#define YP A0  // must be an analog pin, use "An" notation!

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 711);
int buttonPushCounter = 1;   // counter for the number of button presses
int lastButtonState = 0;     // previous state of the button
int flag , flagZ ;


float xVal , yVal ;
int cCount=0;
int flagC=0;
int flagK=0;
float kk=0;
int fl=0;
double l =0.00;
unsigned int noTouchCount = 0; //viariable for noTouch
double  k=0;
// PID values
double Setpoint, Input, Output; //for X
double Setpoint1, Input1, Output1; //for Y
//
int Modulo;
long lastcas=0;
// servos variables
Servo servo1; //X axis
Servo servo2; //Y axis  

float convertX = 1.0;//151.0 / 955.0;  // converts raw x values to mm. found through manual calibration
float convertY = 1.0;//91.0 / 927.0;   // converts raw y values to mm. found through manual calibration
/////TIME SAMPLE
int Ts = 50; 
unsigned long Stable=0, iter=0; 
//PID const
float Kp = 0.1;                                                     
float Ki = 0.01;                                                      
float Kd = 0.04;

float Kp1 = Kp;                                                       
float Ki1 = Ki;                                                      
float Kd1 = Kd;
long cas=0; 
//INIT PID
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, REVERSE);
PID myPID1(&Input1, &Output1, &Setpoint1,Kp1,Ki1,Kd1, REVERSE);

void setup()
{
  servo1.attach(2);
  servo2.attach(3);
  Output=90;
  Output1=90;
  servo1.write(Output);
  servo2.write(Output1);
 
  //INIT PINS
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(9,LOW); //LED INIT
  digitalWrite(8,LOW);

  Serial.begin(115200);
  
  //INIT OF TOUSCHSCREEN
   TSPoint p = ts.getPoint();
 //Input=120;
 //Input1=65;
  //INIT SETPOINT
  Setpoint=500;
  Setpoint1=500 ;
  //// Make plate flat
  servo1.attach(2); 
  servo2.attach(3);
  Output=90;
  Output1=90;
  servo1.write(Output);
  servo2.write(Output1);
  
  //Zapnutie PID
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(90-25, 90+25);
  myPID1.SetMode(AUTOMATIC);
  myPID1.SetOutputLimits(90-25, 90+25);
  // TIME SAMPLE
  myPID1.SetSampleTime(Ts); 
  myPID.SetSampleTime(Ts);  
  /////
  delay(50);
  
 
  ///
 }
 
double tau, theta;
 
void loop()
{
  while(1) //REGULATION LOOP
  {
    tau = 6.2832;
    theta = fmod(iter/500.0, tau);
    iter += 1;
    //Setpoint=510+175*cos(theta);
    //Setpoint1=560+175*sin(theta);
    
   TSPoint p = ts.getPoint();   //measure pressure on plate
//     Serial.print("X = "); Serial.print(Input);
//     Serial.print("\tY = "); Serial.print(Input1);
//     Serial.print("\tPressure = "); Serial.print(p.z);
//     Serial.print("\tStable = "); Serial.println(Stable);
   if (p.z > -ts.pressureThreshhold) //ball is on plate
   {  
      setDesiredPosition();  
      noTouchCount = 0;  
      TSPoint p = ts.getPoint(); // measure actual position 
      Input=(p.x * convertX);  // read and convert X coordinate
      Input1=(p.y * convertY); // read and convert Y coordinate
      
              Stable=Stable+1; //increment STABLE
          if((Input>Setpoint-2 && Input<Setpoint+2 && Input1>Setpoint1-2 && Input1<Setpoint1+2))//if ball is close to setpoint
          {
              Stable=Stable+1; //increment STABLE
              digitalWrite(9,HIGH);
                 
          }
          else
          {
              digitalWrite(9,LOW);
          }
       myPID.Compute();  //action control X compute
       myPID1.Compute(); //   action control  Y compute  
     Serial.print("Input = "); Serial.print(Input);
     Serial.print("\tInput1 = "); Serial.print(Input1); 
     Serial.print("Output = "); Serial.print(Output);
     Serial.print("\tOutput1 = "); Serial.println(Output1); 
    
  }
   else //if there is no ball on plate
  {
    noTouchCount++; //increment no touch count

  }
  servo1.write(Output);//control
  servo2.write(Output1);//control 
  //Serial.print(Setpoint);   Serial.print(",");  Serial.print(Setpoint1);  Serial.print(",");  Serial.print(Input);Serial.print(","); Serial.println(Input1); 
     
}////END OF REGULATION LOOP///
  
  servo1.detach();//detach servos
  servo2.detach();
  
 ///KONTROLA STABILITY////
 while(Stable==125)//if is stable
 { //still measure actual postiion
    setDesiredPosition(); 
    TSPoint p = ts.getPoint();
     Input=(p.x * convertX);  //read X
      Input1=(p.y * convertY); //read Y
    if(Input<Setpoint-2 || Input>Setpoint+2 || Input1>Setpoint1+2 || Input1<Setpoint1-2  ) //if ball isnt close to setpoint
    {
      servo1.attach(5); //again attach servos
      servo2.attach(6);
      digitalWrite(9,LOW);
      Stable=0; //change STABLE state
    }
    
  }//end of STABLE LOOP
}//loop end

////////////////////////Functions////////////////// 
///// DESIRED POSITION
void setDesiredPosition()
{
}
 

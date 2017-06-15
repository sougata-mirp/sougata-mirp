#define  YP A0
#define  XP A1
#define YN  A2
#define XN  A3
#define Xresolution 740
#define Yresolution 645
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 711);
#include <PID_v1.h>
#include <Servo.h>
#include <"TouchScreen.h">

int yServoPin =2;
int xServoPin =3;
int mn=60,mx=120;
int X,Y;
double Input,Output,Setpoint;
double Input1,Onutput1,Setpoint1;

Servo ServoX,ServoY;
float Kp=0.0008;
float Ki=0.0008;
float Kd=0.0008;

float Kp1=0.0008;
float Ki1=0.0008;
float Kd1=0.0008;

PID myPID(&Input,&Output,Setpoint,Kp,Ki,Kd,DIRECT)
PID myPID1(&Input1,&Output1,Setpoint1,Kp1,Ki1,Kd1,DIRECT)
void setup() {
 
  ServoX.attach( xServoPin );
  ServoY.attach( yServoPin );
 
  Output=60;
  Output1=60;
  ServoX.write(Output );
 ServoY.write(Output1 );

Setpoint=510;
Setpoint1=560;

myPID.SetMode(Automatic);
myPID.OutputLimits(mn,mx);
myPID.SetSampleTime(ts);
 
      Serial.begin(9600);                    // put your setup code here, to run once:
 ServoX.attach( xServoPin );
  ServoY.attach( yServoPin );
 
  Output=60;
  Output1=60;
  ServoX.write(Output );
 ServoY.write(Output1 );
Setpoint=510;
Setpoint1=560;
 myPID1.SetMode(Automatic);
myPID1.OutputLimits(mn,mx);
myPID1.SetSampleTime(ts);
 
}

void loop() {
  TSPoint p = ts.getPoint();
 X=p.x;
 Y=p.y;
 
  // put your main code here, to run repeatedly:

}

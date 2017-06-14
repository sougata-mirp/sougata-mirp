float previousError = 0.0, currentError,dvalue;
float angleError = 0.02;

void solution (){
  
     currentError = desiredX-ballX;
  float Kp = 0.0003;
  float anglevalue =  Kp*currentError;
   float Kd = 0.004;
  float dvalue = (currentError -previousError);
 anglevalue+=Kd*dvalue;
  gotoAngle(anglevalue);
  previousError= currentError;
}
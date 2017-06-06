int displayWidth = 200;
int displayHeight = 10;
float r=10.0
int numcircles=5
int ellipseColor=100;
void setup(){
  size(displayWidth,displayHeight);
}
void draw(){
  if(mousepressed){
    drawTarget(mouseX,mouseY,numCircles);
  delay(200);
  }
}
  
  
  background(255);
  void drawCircles()(float r,int
  void drawCircle(float r){
    fill(0);
    ellipse(mouseX,mouseY,25+r,25+r);
    
    
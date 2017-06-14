int displayWidth=1000, displayHeight=500;
int fps = 60;
int pivotPos = displayHeight*3/5;

float desiredX = displayWidth/2;

float beamAngle = 0.0;
float desiredBeamAngle = 0.0;
float desiredAngle = 0.0;
float beamAngleIncrement = 0.1/(0.3*fps);

float beamLength = 750/2;
float beamWidth = 20/2;

color bgColor = color(237,231,246);
int ballColor = 159;
color beamColor = color(255,183,77);

float gravity = 9.81*5000/(fps*fps);
float ballX = displayWidth/2;
float ballY = displayHeight/5;
float ballVx, ballVy;
float ballRadius = 100/2;
float BALL_VELOCITY = 10/2;

char CW = 'd', CCW = 'a';
char LEFT = 'q', RIGHT = 'e';
boolean cw, ccw, left, right;

void simulate() {
  background(bgColor);
  drawBeam();
  drawBall();
  updateBallVelocity();
  updateBallPosition();
  updateBeamAngle();
  moveBeam();
  resolveCollisions();
}

void drawBeam() {
  fill(beamColor);
  rectMode(RADIUS);
  noStroke();
  strokeCap(ROUND);
  pushMatrix();
  translate(displayWidth/2, pivotPos);
  rotate(beamAngle);
  translate(-displayWidth/2, -pivotPos);
  rect(displayWidth/2, displayHeight/2, beamLength, beamWidth);
  popMatrix();
}

void drawBall() {
  fill(ballColor);
  ellipse(ballX, ballY, 2*ballRadius, 2*ballRadius);
}
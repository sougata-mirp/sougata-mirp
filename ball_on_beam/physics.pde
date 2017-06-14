void updateBallVelocity() {
  ballVy += gravity;
}

void updateBallPosition() {
  ballX += ballVx;
  ballY += ballVy;
  if (left)
    ballX -= BALL_VELOCITY;
  if (right)
    ballX += BALL_VELOCITY;
}

void resolveCollisions() {
  float m = tan(-beamAngle), c = -pivotPos;
  float dist = m*(ballX-displayWidth/2) + c + ballY;
  dist /= -sqrt(m*m + 1);
  dist -= pivotPos - displayHeight/2 + beamWidth + ballRadius;
  if (dist < 0) {
    float dx = dist*sin(beamAngle), dy = -dist*cos(beamAngle);
    ballX -= dx;
    ballY -= dy;
    float dotProduct = ballVx*cos(-beamAngle) - ballVy*sin(-beamAngle);
    ballVx = dotProduct*cos(-beamAngle);
    ballVy = -dotProduct*sin(-beamAngle);
  }
  dist = sqrt((ballX-displayWidth/2)*(ballX-displayWidth/2) + (ballY-pivotPos)*(ballY-pivotPos));
  if(dist > beamLength){
    ballX += (ballX>displayWidth/2 ? -1 : 1)*10;
    ballVx = 0;
    ballVy = 0;
  }
}

void gotoAngle(float angle) {
  desiredBeamAngle = angle + random(-angleError, angleError);
}

void moveBeam() {
  if (desiredBeamAngle > beamAngle)
    beamAngle += beamAngleIncrement;
  if (desiredBeamAngle < beamAngle)
    beamAngle -= beamAngleIncrement;
}
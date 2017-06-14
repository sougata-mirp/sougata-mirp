void setup() {
  frameRate(fps);
  size(displayWidth, displayHeight);
}

void draw() {
  println(beamAngle);
  simulate();
  if(!left && !right && !cw && !ccw)
    solution();
}

void updateBeamAngle() {
  // Rotate Clockwise
  if (cw)
    gotoAngle(beamAngle + beamAngleIncrement);
  // Rotate Counter Clockwise
  if (ccw)
    gotoAngle(beamAngle - beamAngleIncrement);
}
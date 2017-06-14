void keyPressed() {
  if (key == CW)        cw = true;
  if (key == CCW)       ccw = true;
  if (key == LEFT)      left = true;
  if (key == RIGHT)     right = true;
}

void keyReleased() {
  if (key == CW)        cw = false;
  if (key == CCW)       ccw = false;
  if (key == LEFT)      left = false;
  if (key == RIGHT)     right = false;
}
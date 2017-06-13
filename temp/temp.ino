int rx = 17;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(rx, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(rx, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(rx, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
}

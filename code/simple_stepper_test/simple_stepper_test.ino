// testing a stepper motor with a Pololu A4988 driver board or equivalent
// on an Uno the onboard led will flash with each step
// this version uses delay() to manage timing

byte directionPin = 20;
byte stepPin = 19;
int numberOfSteps = 8000;
byte ledPin = 13;
//int pulseWidthMicros = 432;  // microseconds
int pulseWidthMicros = 50;  // microseconds
int millisbetweenSteps = 0.6; // milliseconds - or try 1000 for slower steps


void setup() {

  
  delay(2000);

  pinMode(stepPin, OUTPUT);
  
 
  for(unsigned int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    
    delay(millisbetweenSteps);
  }
  
}

void loop() {
}


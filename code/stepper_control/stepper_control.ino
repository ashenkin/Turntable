#define DEBUG 1

#include <AccelStepper.h>

// pinout configuration for Teensy 2.0.  Compatible with TeensyTurn.
int stepPin = 21; // aka Pulse
int enblPin = 19;
int dirPin = 20;
int readoutPin = 17;
int triggerPin = 1;
int camShutterPin = 16;

//int steps_per_rot = 200;
const float deg_per_wholestep = 1.8;
const double substeps = 1.0/8.0;
const float deg_per_step = deg_per_wholestep * substeps;

const float speed_deg = 3.0; // deg/sec
const float maxSpeed_deg = 5;   // deg/sec
const float accel_deg = 0.3; // deg/sec/sec
const double gear_division = 0.00387; //MXL 20 tooth gear diameter = 0.685" = 17.4 mm.  Lazy susan diameter = 450mm.  17.4/450 = 0.00387
const double deg_to_steps = (1.0 / deg_per_step) / gear_division;

const double photoaccel = accel_deg * deg_to_steps; // steps/sec/sec
const double photomaxSpeed = maxSpeed_deg * deg_to_steps; // steps/sec
const double photospeed = speed_deg * deg_to_steps; // steps/sec

const double angBetPics = 3.0; // degrees between consecutive pictures
const double stepsBetPics = angBetPics * deg_to_steps; // degrees between consecutive pictures

const double branchSettlingTime = 3000; // ms to let branch settle after motor stops moving and before picture is snapped

void shutterRelease() {
  digitalWrite(camShutterPin, HIGH);
  delay(500);
  digitalWrite(camShutterPin, LOW);
}

//AccelStepper photostepper(AccelStepper::DRIVER, stepPin, dirPin); 
AccelStepper photostepper(AccelStepper::DRIVER, stepPin, dirPin); 

void setup() { 
  
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.print(F("deg_per_wholestep = "));
    Serial.print(deg_per_wholestep);
    Serial.print(F("; deg_per_step = "));
    Serial.print(deg_per_step);
    Serial.print(F("; substeps = "));
    Serial.print(substeps);
    Serial.print(F("; speed = "));
    Serial.print(photospeed);
    Serial.print(F("; deg_per_step = "));
    Serial.print(deg_per_step);
    Serial.print(F("; accel = "));
    Serial.println(photoaccel);
    Serial.print(F("; photomaxSpeed = "));
    Serial.println(photomaxSpeed);
  #endif

  delay(2000);
  photostepper.setEnablePin(enblPin);
  photostepper.setMaxSpeed(photomaxSpeed);
  photostepper.setAcceleration(photoaccel); 
  photostepper.setSpeed(photospeed);  
  
  photostepper.setPinsInverted(false, false, true);   
  photostepper.enableOutputs();

  //pinMode(readoutPin, INPUT);
  //pinMode(triggerPin, INPUT_PULLUP);
  
  //Serial.println(F("Turntable Initialized"));

  pinMode(camShutterPin, OUTPUT);
  digitalWrite(camShutterPin, LOW);
}

void loop() {
  Serial.println("in the loop");
  //photostepper.runSpeed();
  photostepper.move(stepsBetPics);
  photostepper.runToPosition();  // blocks
  photostepper.disableOutputs();  // save power, but no holding torque
  delay(branchSettlingTime);
  shutterRelease();
  photostepper.enableOutputs();
}

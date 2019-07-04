/*

        MGX3D 3D Scanning Turntable Controller


Copyright (c) 2015, Marius Gheorghescu. All rights reserved.

mariusg (at) live.com / www.mariusg.com / www.github.com/mgx3d/


Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

1. Redistributions of source code must retain the above copyright 
notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright 
notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/


// pinout configuration for Teensy 2.0
int stepPin = 19; // aka Pulse



void run_motor(int doIO, unsigned int nSteps, unsigned int lhDelay, unsigned int hlDelay, unsigned int accRamp=0, unsigned int accBeta=0)
{
  

  // run the motor

  
  for (unsigned int i=0; i<nSteps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(hlDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(lhDelay);
  }

}


void setup()
{
  pinMode(stepPin, OUTPUT);
    
  run_motor(1, 800, 432, 432, 0, 0);
  
}


void loop() 
{

}

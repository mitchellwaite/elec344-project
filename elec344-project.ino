#define XPIN A0
#define YPIN A1
#define ZPIN A2
#define POT1 A4
#define POT2 A5
#include "volume2.h"
Volume vol;

unsigned int toneArr[] = { PWM_12, PWM_12, SAWTOOTH, SAWTOOTH, TRIANGLE, TRIANGLE, SINE, SINE };

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(XPIN,INPUT);
  pinMode(YPIN,INPUT);
  pinMode(ZPIN,INPUT);
  pinMode(POT1,INPUT);
  pinMode(POT2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  int toneChoice = 0;
  
  int xVoltage = analogRead(XPIN);
  int yVoltage = analogRead(YPIN);
  int zVoltage = analogRead(ZPIN);
  int p1 = analogRead(POT1);
  int p2 = analogRead(POT2);
  int p1_1 = map(p1, 0, 512, 233, 466);
  int noteChoice = 0;
  //delay(100);

  if(p1 < 128)
  {
    noteChoice = 262;
  }
  else if(p1 < 256)
  {
    noteChoice = 294;
  }
  else if(p1 < 384)
  {
    noteChoice = 330;
  }
  else if(p1 < 512)
  {
    noteChoice = 349; 
  }
  else if(p2 < 128)
  {
    noteChoice = 392;
  }
  else if(p2 < 256)
  {
    noteChoice = 440;
  }
  else if(p2 < 384)
  {
    noteChoice = 494;
  }
  else if(p2 < 512)
  {
    noteChoice = 523; 
  }
  else
  {
    noteChoice = 0;
  }

  //Check le accelerometer
  int noteAdj = map(zVoltage,300,400,0,100);

  if(noteChoice)
  {
     vol.tone(noteChoice + noteAdj,SAWTOOTH,128);
  }
  else
  {
    vol.noTone();
  }
 

  Serial.print(p1);
  Serial.print(',');
  Serial.print(p2);
  Serial.print(',');
  Serial.print(xVoltage);
  Serial.print(',');
  Serial.print(yVoltage);
  Serial.print(',');
  Serial.print(zVoltage);
  Serial.print('\n');
}

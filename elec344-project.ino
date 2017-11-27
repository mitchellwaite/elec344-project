#define XPIN A0
#define YPIN A1
#define ZPIN A2
#define POT1 A4
#define POT2 A5
#include "volume2.h"
Volume vol;

byte toneArr[] = { PWM_12, PWM_12, SAWTOOTH, SAWTOOTH, TRIANGLE, TRIANGLE, SINE, SINE };
byte toneChoice;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A3));
  // put your setup code here, to run once:
  pinMode(XPIN,INPUT);
  pinMode(YPIN,INPUT);
  pinMode(ZPIN,INPUT);
  pinMode(POT1,INPUT);
  pinMode(POT2,INPUT);

  toneChoice = toneArr[random(8)];
  
}

void loop() {
  // put your main code here, to run repeatedly
  
  int xVoltage = analogRead(XPIN);
  int yVoltage = analogRead(YPIN);
  int zVoltage = analogRead(ZPIN);
  int p1 = analogRead(POT1);
  int p2 = analogRead(POT2);
  int p1_1 = map(p1, 0, 512, 233, 466);
  int noteChoice = 0;
  //delay(100);



  if(p2 < 128)
  {
    if(p1 < 10)
    {
      noteChoice = 392;
    }
    else
    {
      noteChoice = 262;
    }
  }
  else if(p2 < 256)
  {
    if(p1 > 10)
    {
      noteChoice = 294;
    }
    else
    {
      noteChoice = 440;
    } 
  }
  else if(p2 < 384)
  {
    if(p1 > 10)
    {
       noteChoice = 330;
    }
    else{
      noteChoice = 494;
    }
    
  }
  else if(p2 < 512)
  {
    if(p1 > 10)
    {
      noteChoice = 349;
    }
    else
    {
      noteChoice = 523; 
    }
    
  }
  else
  {
    noteChoice = 0;
  }

  //Check le accelerometer
  int noteAdj = map(zVoltage,300,400,0,100);

  if(noteChoice)
  {
     vol.tone(noteChoice + noteAdj,toneChoice,128);
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
  Serial.print(',');
  Serial.print(toneArr[random(8)]);  
  Serial.print('\n');
}

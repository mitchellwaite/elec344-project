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
  byte wave[32] = {
    255,255,192,192,192,192,128,128,
    192,192,128,128,128,128,64,64,
    192,192,128,128,128,128,64,64,
    128,128,64,64,64,64,0,0,
  };
  vol.setCustomWave(wave);
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
  //delay(100);

  if(xVoltage > 337)
    toneChoice |= 1;

  if(yVoltage > 337)
    toneChoice |= 2;

  if(zVoltage > 337)
    toneChoice |= 4;

  if(p1_1 < 512)
  {
    vol.tone(p1_1, toneArr[toneChoice], 64);
  }
  else
  {
    vol.noTone();
  }
  
  Serial.println(p1);
  //Serial.println(p2);
}

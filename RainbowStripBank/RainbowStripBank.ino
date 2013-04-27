/*
 Rainbow 3
 
 This example shows how to cycle through the colors 
 of the rainbow using the analogWrite() function.
 
 This example code is in the public domain.
 
 */

#include <Encabulator.h>
//#include <Wire.h>
#include <I2C.h>   // NOTE: For reasons buried in the Encabulator.cpp file, you might want to download and use this library instead. 

//
// pins defined
//
#define REDID    0
#define GREENID  1
#define BLUEID   2
#define MIN_COLOR REDID
#define MAX_COLOR BLUEID

int colorID = REDID;

//#define RED    0x01
//#define GREEN  0x02
//#define BLUE   0x04


int brightness = 5;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

//
// length of pulse in period over 1024
//
#define PWM_MIN_VAL  0
#define PWM_MAX_VAL  255
#define PWM_DEF_VAL  ((int)((PWM_MAX_VAL+PWM_MIN_VAL)/2.0))
int pwmDutyCycle[3] = {
  PWM_DEF_VAL, PWM_DEF_VAL, PWM_DEF_VAL};

// modulating background color
//float oSpeed = .000075;
float oSpeed = 0.00075;

const float rOffset = PWM_DEF_VAL/(float)PWM_MAX_VAL;
const float gOffset = PWM_DEF_VAL/(float)PWM_MAX_VAL;
const float bOffset = PWM_DEF_VAL/(float)PWM_MAX_VAL;

int rValue = PWM_MAX_VAL;
int gValue = PWM_MAX_VAL;
int bValue = PWM_MAX_VAL;


int loopCounter=0;

void setup()  {
  delay(5000);

  Encabulator.upUpDownDownLeftRightLeftRightBA();

  // enable some debugging on the serial port

  Encabulator.setVerbose(true);

  // quickly fade all 12V RGB headers down to black
  for (int i=1; i<5; i++) {
    Encabulator.stripBankA.jumpHeaderToRGB(i,0,0,0); 
    Encabulator.stripBankB.jumpHeaderToRGB(5-i,0,0,0);
    delay(250);
  }

  // jump all 12V RGB headers up to red
  for (int i=1; i<5; i++) {  
    Encabulator.stripBankA.fadeHeaderToRGB(i,255,0,0,20); 
    Encabulator.stripBankB.fadeHeaderToRGB(5-i,255,0,0,20);
    delay(250);
  }

  delay(1500);

  // quickly fade all 12V RGB headers down to black
  for (int i = 1 ; i < 5 ; i++) {
    Encabulator.stripBankA.fadeHeaderToRGB(i,0,0,0,20); 
    Encabulator.stripBankB.fadeHeaderToRGB(5-i,0,0,0,20);
    delay(250);
  }

  delay(1000);
} 


void loop()  { 
  // set the brightness of led pin:
  //updateColor(0);
  for (int i=1; i<5; i++) {  
    updateColor(i*PI/4);
    Encabulator.stripBankA.fadeHeaderToRGB(i,rValue,gValue,bValue,20); 
    Encabulator.stripBankB.fadeHeaderToRGB(5-i,rValue,gValue,bValue,20);
    delay(500);
  }

#if DEBUG  
  Serial.print(rValue);
  Serial.print(", ");
  Serial.print(gValue);
  Serial.print(", ");
  Serial.println(bValue);
#endif

  if (0 == loopCounter%8) {
    // quickly fade all 12V RGB headers down to black
    Serial.println(loopCounter%256);
    for (int i = 1 ; i < 5 ; i++) {
      Encabulator.stripBankA.fadeHeaderToRGB(i,0,0,0,20); 
      Encabulator.stripBankB.fadeHeaderToRGB(5-i,0,0,0,20);
      delay(500);
    }
    delay(2000);
  }

  loopCounter++;

  // wait for 30 milliseconds to see the dimming effect    
  delay(100);
}


void updateColor(float timeOffset) {
  float tm = (float) millis() * oSpeed + timeOffset;

  bValue = (int)constrain((PWM_MAX_VAL*(sin(tm)/2+rOffset)), PWM_MIN_VAL, PWM_MAX_VAL);
  gValue = (int)constrain((PWM_MAX_VAL*(sin(tm+TWO_PI/3)/2+gOffset)), PWM_MIN_VAL, PWM_MAX_VAL);
  rValue = (int)constrain((PWM_MAX_VAL*(sin(tm+2*TWO_PI/3)/2+bOffset)), PWM_MIN_VAL, PWM_MAX_VAL);
}






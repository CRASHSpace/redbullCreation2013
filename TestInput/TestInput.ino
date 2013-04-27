/*
 * Danger Shield Example Sketch
 * Copyright (c) 2010 SparkFun Electronics.  All right reserved.
 * Written by Chris Taylor
 *
 * This code was written to demonstrate the Danger Shield from SparkFun Electronics
 * 
 * This code will test all of the devices on the Danger Shield one at a time. 
 * Press button 1 (D10) to cycle through the different tests. View their output on 
 * a terminal running at 9600 baud. 
 *
 * http://www.sparkfun.com
 */
#include <string.h>


// Global variables
int val = 0;
char buff[32] = "";
int colorVal[3] = {
  0,0,0};

// Pin definitions
#define SLIDER1  A2
#define SLIDER2  A1
#define SLIDER3  A0


#define SLED1  11
#define SLED2  10
#define SLED3  9

#define KNOCK    A5

#define BUTTON1  2
#define BUTTON2  7
#define BUTTON3  4

#define LED1  6
#define LED2  5

#define BUZZER   3

#define TEMP  A4

#define LIGHT  A3

#define LATCH 8
#define CLOCK 12
#define DATA 1

#define DEBOUNCE_TIME 5
#define SERIAL_DELAY 25
#define LOOP_DELAY 250

#define RANGEPLUS 32
#define RANGEMINUS 32

void setup()
{
  Serial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  pinMode(BUZZER, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA,OUTPUT);

  Serial.println("Danger Shield Component Test");  
  Serial.println("Press Button 1 to begin.");  
}

void loop()
{
  boolean buttonPressed = false;

  if(digitalRead(BUTTON1)) {
    delay(DEBOUNCE_TIME); // Debounce
    if (digitalRead(BUTTON1)) {
      buttonPressed = true;
      Serial.println("b0");
      delay(SERIAL_DELAY);
      buttonPressed = true;
    }
  }

  if(digitalRead(BUTTON2)) {
    delay(DEBOUNCE_TIME); // Debounce
    if (digitalRead(BUTTON2)) {
      buttonPressed = true;
      Serial.println("b1");
      buttonPressed = true;
    }
  }

  if(digitalRead(BUTTON3)) {
    delay(DEBOUNCE_TIME); // Debounce
    if (digitalRead(BUTTON3)) {
      Serial.println("b2");
      delay(SERIAL_DELAY);
      buttonPressed = true;
    }
  }

  if (!buttonPressed) {

    val = analogRead(SLIDER1)>>2;
    if (val != colorVal[0]) {
      long minVal = ((val-RANGEMINUS)<0) ? 0 : val-RANGEMINUS;
      long maxVal = ((val+RANGEPLUS)<=255) ? val+RANGEPLUS : 255;
      colorVal[0] = val;

      sprintf(buff,"var0min%03d\n",minVal);
      Serial.print(buff);
      delay(SERIAL_DELAY);
      sprintf(buff,"var0max%03d\n",maxVal);
      Serial.print(buff);
      delay(SERIAL_DELAY);
    }
    val = analogRead(SLIDER2)>>2;
    if (val != colorVal[1]) {
      long minVal = ((val-RANGEMINUS)<0) ? 0 : val-RANGEMINUS;
      long maxVal = ((val+RANGEPLUS)<=255) ? val+RANGEPLUS : 255;
      colorVal[1] = val;

      sprintf(buff,"var1min%03d\n",minVal);
      Serial.print(buff);
      delay(SERIAL_DELAY);
      sprintf(buff,"var1max%03d\n",maxVal);
      Serial.print(buff);
      delay(SERIAL_DELAY);
    }
    val = analogRead(SLIDER3)>>2;
    if (val != colorVal[2]) {
      long minVal = ((val-RANGEMINUS)<0) ? 0 : val-RANGEMINUS;
      long maxVal = ((val+RANGEPLUS)  <= 255) ? val+RANGEPLUS : 255;
      colorVal[2] = val;

      sprintf(buff,"var2min%03d\n",minVal);
      Serial.print(buff);
      delay(SERIAL_DELAY);
      sprintf(buff,"var2max%03d\n",maxVal);
      Serial.print(buff);
      delay(SERIAL_DELAY);
    }
    delay(SERIAL_DELAY);
  }
  else {
    delay(LOOP_DELAY);
  }
}






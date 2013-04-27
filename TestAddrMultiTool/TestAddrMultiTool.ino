#include <Encabulator.h>
//#include <Wire.h>
#include <I2C.h>   // NOTE: For reasons buried in the Encabulator.cpp file, you might want to download and use this library instead. 

int loopCounter = 0;

int tempR = 0;
int tempG = 0;
int tempB = 0;

float tempX = 0.0;
float tempY = 0.0;

float tempC = 0.0; 

int tempLength = 64; 

int palindrome = 0; 

int ledCnt = 4*64;

void setup() {               
  delay(2000);
  
  Encabulator.upUpDownDownLeftRightLeftRightBA();

  // enable some debugging on the serial port

  Encabulator.setVerbose(true);

  //Encabulator.addressable.drawGradient(random() % 255,random() % 255,0,0,random() % 255,random() % 255,64);

  delay(500);

  Encabulator.addressable.drawGradient(0,0,0,0,0,0,ledCnt);

  delay(500);

}

void loop() {

  palindrome = (loopCounter % 510 > 255) ? 255 - (loopCounter % 510) : loopCounter % 510;
  
//  tempX = Encabulator.accelerometer.x() / 1024.0;
//  tempY = Encabulator.accelerometer.y() / 1024.0;
//
//  tempR = abs(tempX * 255.0);
//  tempG = 0;
//  tempB = abs(tempY * 255.0);
//  
//
//  Encabulator.addressable.drawGradient(tempR,0,tempB,0,0,255,64);
  //Encabulator.addressable.blackout();
  //delay(50);
  //Encabulator.addressable.drawGradient(0,0,0,(loopCounter%256),0,0,64);
  //Encabulator.addressable.drawGradient(0,0,0,0,64/*(loopCounter%256)*/,0,64);
  //Encabulator.addressable.drawGradient(0,0,0,0,0,128/*(loopCounter%256)*/,63*5);
  ledCnt = 128;
  Encabulator.addressable.drawGradient(0,0,0,0,0,128,ledCnt);
  Serial.println(loopCounter);
  delay(500);
  
  // increment loop
  
  loopCounter++;
 
}

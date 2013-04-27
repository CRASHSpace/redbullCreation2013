#include <Encabulator.h>
//#include <Wire.h>
#include <I2C.h>   // NOTE: For reasons buried in the Encabulator.cpp file, you might want to download and use this library instead. 

int loopCounter = 0;

void setup() {               
  delay(5000);

  Encabulator.upUpDownDownLeftRightLeftRightBA();

  // enable some debugging on the serial port

  Encabulator.setVerbose(true);

  delay(1000);

  // check EEPROM   


  //for (int32_t i=0xffff; i>-1; i--) {
  //for (int32_t i=0; i<0xffff; i++) {
  for (int32_t i=0xffff; i>0xf800; i--) {
  //for (int32_t i=0; i<58; i++) {

    Serial.print((char) Encabulator.eeprom.readAddress(i));
    //if (0 == i%32) {
      //Serial.println();
    //}
  }
  Serial.println();
  Serial.println();

  delay(5000);
}

void loop() {               
  //  for (uint16_t i=0; i<1024; i++) {
  //    for (uint16_t j=0 ; j < 64 ; j++) {
  //      Serial.print((char) Encabulator.eeprom.readAddress(i*16+j));
  //    }  
  //    Serial.println();
  //  }
  //  Serial.println();
  //  Serial.println();

  delay(5000);
}






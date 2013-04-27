/*******************************************
 * Sample sketch that configures an HMC5883L 3 axis
 * magnetometer to continuous mode and reads back 
 * the three axis of data.
 * Code compiles to a size of 1500 bytes
 * Equivalent Wire Library code compiles to 2032 bytes
 *******************************************/

#include <Encabulator.h>
#include <I2C.h>

#include <stdio.h>

#define DUT LG_RGB_4X_A  // 0x20
//#define DUT LG_RGB_4X_B  // 0x20
//#define DUT LG_DMX_1X  // 0x40
//#define DUT LG_ADDR_1X  //0x50

void setup()
{
  Serial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  I2c.begin();

  delay(3000);
  Serial.println("Wait for it.");
  delay(1500);
  Serial.println("Wait for it.");
  delay(1500);
  Serial.println("Let the probing begin!!!");
}

void loop()
{
  uint8_t c;
  char buff[32];

  for (int i=0; i<256; i++) {
    I2c.read(DUT,i,1);
    c = I2c.receive();
    sprintf(buff,"%3i: 0x%X",i,c);
    Serial.println(buff);
    delay(50);
  }
  delay(5000);
}




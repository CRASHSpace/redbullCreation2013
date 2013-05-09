redbullCreation2013
===================

Arduino firmware for LED display built for Red Bull Creation 2013

- TestInput
Firmware for the danger shield input device.

- VideoDisplay
Video display driver for teensy 3.0 using DMA from:
http://www.pjrc.com/teensy/td_libs_OctoWS2811.html

- RainbowStripBank
Display a rainbow pattern on the bank of strip drivers.
depends on : https://code.google.com/p/turbull-encabulator/


Testing/exploring of RB shield:
- ProbeAll
Read all possible I2C registers for devices on RB shield

- ReadFlash
Reading of RB shield external flash

- TestAddrMultiTool
Confirming firmware bug in RB shield addressable led driver 


Processing code for pushing and displaying content on the CrashInspired Star:
- CrashInspiredTransmitter 
( another repo forked from HackRockCity in NYC) 
https://github.com/CRASHSpace/CrashInspiredTransmitter

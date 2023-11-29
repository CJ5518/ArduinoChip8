#include <Arduino.h>
#include "cjLCD.hpp"

const byte CS = 8;
const byte SCLK = 10;
const byte SID = 9;

LCD lcd;

void setup() {
	delay(1000);

	//Make the built in LED and the 3 LCD pins outputs
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(CS, OUTPUT);
	pinMode(SID, OUTPUT);
	pinMode(SCLK,OUTPUT);

	digitalWrite(CS, 0);
	digitalWrite(SID, 0);
	digitalWrite(SCLK, 0);

	lcd.init(CS, SCLK, SID);

	//display on, no cursor
	lcd.setDisplay(1, 0, 0);
	delayMicroseconds(72);
	lcd.functionSet(1);
	delay(1);
	lcd.setGRAMAddress(0,0);
	delayMicroseconds(72);
	lcd.writeRAM(0x00);
	delayMicroseconds(72);
	lcd.writeRAM(0x00);
	delayMicroseconds(72);

	
	
}

byte cursorX = 0;
byte cursorY = 0;
bool goAgain = true;

void loop() {
	
}

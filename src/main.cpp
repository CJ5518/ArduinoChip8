#include <Arduino.h>
#include "cjLCD.hpp"

const byte CS = 5;
const byte SCLK = 6;
const byte SID = 7;

LCD lcd;

void setup() {
	delay(1000);
	//Make buttons inputs
	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);

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
	lcd.functionSet(1);
	delay(1);

	for (int x = 0; x <= 0xFF; x++) {
		for (int y = 0; y <= 0xFF; y++) {
			lcd.sendByte(0,0,0x80 | x);
			lcd.sendByte(0,0,0x80 | y);

			for (int i = 0; i < 32; i++) {
				lcd.sendByte(1, 0, 0b10101010);
			}
		}
	}
	
	
}

void loop() {
}

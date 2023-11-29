#include <Arduino.h>
#include "cjLCD.hpp"

const byte CS = 8;
const byte SCLK = 10;
const byte SID = 9;

LCD lcd;


void setup() {
	delay(255);

	//Make the built in LED and the 3 LCD pins outputs
	pinMode(CS, OUTPUT);
	pinMode(SID, OUTPUT);
	pinMode(SCLK,OUTPUT);

	PORTD = 0;

	lcd.init(CS, SCLK, SID);

	//display on, no cursor
	lcd.setDisplay(1, 0, 0);
	delayMicroseconds(72);
	lcd.functionSet(1);
	delay(1);
	lcd.clearBoard();
	lcd.drawBoard();
	
}

void loop() {
	
}

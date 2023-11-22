#include <Arduino.h>
#include "cjLCD.hpp"

const byte CS = 0;
const byte SCLK = 1;
const byte SID = 2;

LCD lcd;

void setup() {
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
	delay(1);
	
}

void loop() {
}

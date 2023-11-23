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
	

	
	
}

byte cursorX = 0;
byte cursorY = 0;
bool goAgain = true;

void loop() {
	if (!digitalRead(8) && goAgain) {
		cursorX++;
		goAgain = false;
	} else if (!digitalRead(9) && goAgain) {
		cursorX--;
		goAgain = false;
	} else if (!digitalRead(10) && goAgain) {
		cursorY++;
		goAgain = false;
	} else if (!digitalRead(11) && goAgain) {
		cursorY--;
		goAgain = false;
	} else {
		goAgain = true;
	}

	lcd.setGRAMAddress(cursorX, cursorY);
	lcd.writeRAM(0xFF); lcd.writeRAM(0xFF);
	delay(30);
	lcd.setGRAMAddress(cursorX, cursorY);
	lcd.writeRAM(0x00); lcd.writeRAM(0x00);
	delay(30);

}

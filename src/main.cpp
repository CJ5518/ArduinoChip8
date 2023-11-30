#include <Arduino.h>
#include "cjLCD.hpp"
#include "keypad.hpp"
#include "cjChip8LowMem.hpp"
#include "cjChip8Roms.hpp"

const byte CS = 8;
const byte SCLK = 10;
const byte SID = 9;

LCD lcd;
Keypad keypad;
Chip8 chip8;

//Get rid of this when done testing (wastes precious ram)
char keypadCharLookup[] = {
	'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
};

void setup() {
	delay(255);

	//Make the built in LED and the 3 LCD pins outputs
	pinMode(CS, OUTPUT);
	pinMode(SID, OUTPUT);
	pinMode(SCLK,OUTPUT);

	for (int q = 0; q < 8; q++) {
		pinMode(q, INPUT);
	}
	pinMode(8, OUTPUT);
	pinMode(13, OUTPUT);
	keypad.rowPins[0] = 7;
	keypad.rowPins[1] = 0;
	keypad.rowPins[2] = 1;
	keypad.rowPins[3] = 3;

	keypad.colPins[0] = 2;
	keypad.colPins[1] = 4;
	keypad.colPins[2] = 5;
	keypad.colPins[3] = 6;
	keypad.init();

	lcd.init(CS, SCLK, SID);

	//display on, no cursor
	lcd.setDisplay(1, 0, 0);
	delayMicroseconds(72);
	lcd.functionSet(1);
	delay(1);
	lcd.clearBoard();
	lcd.drawChar(0, 0, 'A');
	lcd.drawString(1,0,"Hello, World!");
	lcd.drawBoard();

	chip8.lcd = &lcd;
	chip8.keypad = &keypad;
	chip8.loadROM(tetris, sizeof(tetris));
}

int count = 0;
void loop() {
	keypad.updateState();
	for (byte q = 0; q < 16; q++) {
		if (keypad.keypad[q]) {
			lcd.drawChar(count, 0, keypadCharLookup[q]);
			count++;
			if (count == 16) count = 0;
		}
	}
	lcd.drawBoard();
}

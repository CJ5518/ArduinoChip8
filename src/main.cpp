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

struct menuEntry {
	const char* name;
	const byte* location;
	int size;
};

#define ITEM(n,l) {n,l,sizeof(l)}

menuEntry menu[] {
	ITEM("test1",test_1),
	ITEM("test2",test_2),
	ITEM("test3",test_3),
	ITEM("maze",maze),
	ITEM("minimal", minimalGame),
	ITEM("snake",snake),
	ITEM("logo1",chip8Picture),
	ITEM("pong",pong),
	ITEM("brick",brickBrixHack),
	ITEM("missile",missile),
	ITEM("tetris",tetris),
	ITEM("tron",tron),
	ITEM("submarine",submarine),
};
byte menuTop = 0;
byte cursorItem = 0;

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
	lcd.drawBoard();
	chip8.lcd = &lcd;
	chip8.keypad = &keypad;
}

int count = 0;
bool wait = true;
void loop() {
	
	
	while (wait) {
		//Menu part
		byte menuLength = sizeof(menu) / sizeof(menuEntry);
		if (menuTop > cursorItem) {
			menuTop = cursorItem;
		}
		if (menuTop < cursorItem-7 && menuLength -(cursorItem-7) >= 8) {
			menuTop = cursorItem-7;
		}

		//Draw where we are
		for (byte q = 0; q < 8; q++) {
			lcd.drawString(2, q * 8, (char*)menu[menuTop+q].name);
			
			lcd.drawChars(0, q * 8, 0, 0);
		}
		
		lcd.drawChars(0, (cursorItem-menuTop) * 8, '!', 0);

		while (true) {
			keypad.updateState();
			if (keypad.keypad[2] && cursorItem > 0) {
				cursorItem--;
				break;
			}
			if (keypad.keypad[8] && cursorItem+1 < menuLength) {
				cursorItem++;
				break;
			}
			if (keypad.keypad[0xF]) {
				chip8.loadROM(menu[cursorItem].location, menu[cursorItem].size);
				wait = false;
				break;
			}
		}
	}

	//Chip8 part
	srand(micros());
	keypad.updateState();
	
	for (byte q = 0; q < 20; q++) {
		if (chip8.exceptionFlags) {
			if (chip8.exceptionFlags & chip8.NO_MEMORY) {
				lcd.drawString(0, 0, "NO_MEMORY");
			}
			if (chip8.exceptionFlags & chip8.STACK_OVERFLOW) {
				lcd.drawString(0, 1 * 8, "STACK_OVERFLOW");
			}
			if (chip8.exceptionFlags & chip8.STACK_UNDERFLOW) {
				lcd.drawString(0, 2 * 8, "STACK_UNDERFLOW");
			}
			if (chip8.exceptionFlags & chip8.UNKNOWN_OPCODE) {
				lcd.drawString(0, 3 * 8, "UNKNOWN_OPCODE");
			}
			if (chip8.exceptionFlags & chip8.BAD_LCD_COORDS) {
				lcd.drawString(0, 4 * 8, "BAD_LCD_COORDS");
			}
			char buff[16];

			sprintf(buff, "%d", (int)chip8.instructionsExecuted);
			lcd.drawString(0, 5 * 8, buff);

			sprintf(buff, "%d", (int)chip8.exceptionInfo);
			lcd.drawString(0, 6 * 8, buff);
			//Doesn't work for some reason I cannot begin to understand
			//Will work if the above sprintf isn't there
			sprintf(buff, "%d", (int)chip8.exceptionInfo2);
			lcd.drawString(0, 7 * 8, buff);


			while (true) {}
		}
		chip8.tick();
		if (chip8.delayTimer)
			chip8.delayTimer--;
		if (chip8.soundTimer)
			chip8.soundTimer--;
	}
	lcd.drawBoard();
}

#include "keypad.hpp"
#define nop asm volatile ("nop\n\t")

void Keypad::init() {
	clearKeypadState();
	decoderArray[0] = 1;
	decoderArray[1] = 2;
	decoderArray[2] = 3;
	decoderArray[3] = 0xA;
	decoderArray[4] = 4;
	decoderArray[5] = 5;
	decoderArray[6] = 6;
	decoderArray[7] = 0xB;
	decoderArray[8] = 7;
	decoderArray[9] = 8;
	decoderArray[10] = 9;
	decoderArray[11] = 0xC;
	decoderArray[12] = 0xE;
	decoderArray[13] = 0;
	decoderArray[14] = 0xF;
	decoderArray[15] = 0xD;

	//All 8 pins as inputs
	DDRD = 0;
	//Set the 4 columns to have pullup resistors
	PORTD |= (1 << 2);
	PORTD |= (1 << 4);
	PORTD |= (1 << 5);
	PORTD |= (1 << 6);
}

void Keypad::updateState() {
	for (int q = 0; q < 4; q++) {
		int rowPin = rowPins[q];
		//set ROWn to 1 (for safety, but possibly redundant)
		bitSet(PORTD, rowPin);
		//make ROWn an output
		bitSet(DDRD, rowPin);
		//clear ROWn to 0
		bitClear(PORTD, rowPin);
		//delay for ~1uS with nop()s or delayMicroseconds(1)
		nop; nop;
		//read column inputs (columns should be configured as INPUT_PULLUP)
		for (int i = 0; i < 4; i++) {
			int colPin = colPins[i];
			int buttonState = !(PIND & (1 << colPin));
			keypad[decodeKeypad(q,i)] = buttonState;
		}
		//set ROWn to 1 (forces high state w/o waiting for slow rise time from pullups)
		bitSet(PORTD, rowPin);
		
		//make all ROWs inputs again (previously setting ROWn to 1 will configure the pin as INPUT_PULLUP)
		DDRD = 0;
	}
}

byte Keypad::decodeKeypad(byte row, byte col) {
	return decoderArray[(row * 4) + col];
}


inline void Keypad::clearKeypadState() {
	memset(keypad, 0, sizeof(bool) * 16);
}

#include "cjLCD.hpp"

#define nop asm volatile ("nop\n\t")


//Lower level functions
void LCD::flipSclk() {
	digitalWrite(SCLK, 1);
	nop; nop;
	digitalWrite(SCLK, 0);
}
void LCD::sendBit(byte bit) {
	digitalWrite(SID, bit);
	flipSclk();
}
void LCD::sendByte(byte rs, byte rw, byte thing) {
	digitalWrite(CS, 1);
	sendBit(1);
	sendBit(1);
	sendBit(1);
	sendBit(1);
	sendBit(1);
	sendBit(rw);
	sendBit(rs);
	sendBit(0);
	sendBit(bitRead(thing, 7));
	sendBit(bitRead(thing, 6));
	sendBit(bitRead(thing, 5));
	sendBit(bitRead(thing, 4));
	sendBit(0);
	sendBit(0);
	sendBit(0);
	sendBit(0);
	sendBit(bitRead(thing, 3));
	sendBit(bitRead(thing, 2));
	sendBit(bitRead(thing, 1));
	sendBit(bitRead(thing, 0));
	sendBit(0);
	sendBit(0);
	sendBit(0);
	sendBit(0);
	digitalWrite(CS, 0);
}

//Interface to commonly used functions
void LCD::setDisplay(bool display, bool cursor, bool blink) {
    sendByte(0,0,0b1000 | (display << 2) | (cursor << 1) | blink);
}

//Initialization
void LCD::init(int CSbit, int SCLKbit, int SIDbit) {
    CS = CSbit;
    SCLK = SCLKbit;
    SID = SIDbit;
}
LCD::LCD(int CSbit, int SCLKbit, int SIDbit) {
    init(CSbit, SCLKbit, SIDbit);
}
LCD::LCD() {

}


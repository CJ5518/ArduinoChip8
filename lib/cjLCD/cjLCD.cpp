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
void LCD::functionSet(bool extended, bool graphics) {
	sendByte(0, 0, 0b100000 | (extended << 2) | (graphics << 1));
}
void LCD::setGRAMAddress(byte x, byte y) {
	sendByte(0, 0, 0x80 | y);
	sendByte(0, 0, 0x80 | x);
}
void LCD::writeRAM(byte data) {
	sendByte(1,0, data);
}

//Initialization
void LCD::init(byte CSbit, byte SCLKbit, byte SIDbit) {
	CS = CSbit;
	SCLK = SCLKbit;
	SID = SIDbit;
}
LCD::LCD(byte CSbit, byte SCLKbit, byte SIDbit) {
	init(CSbit, SCLKbit, SIDbit);
}
LCD::LCD() {
}

inline int LCD::byteCoordToIdx(byte x, byte y) {
	return x + (y * 16);
}
inline void LCD::byteIdxToCoord(int idx, byte* x, byte* y) {
	*x = idx % 16;
	*y = (idx - *x) / 16;
}
inline int LCD::pixelCoordToIdx(byte x, byte y) {
	return x + (y * 128);
}
inline void LCD::pixelIdxToCoord(int idx, byte* x, byte* y) {
	*x = idx % 128;
	*y = (idx - *x) / 128;
}
void LCD::clearBoard() {
	memset(board, 0, sizeof(board));
}
void LCD::drawBoard() {
	for (byte y = 0; y < 32; y++) {
		setGRAMAddress(0, y);
		//Draw one line
		for (byte x = 0; x < 16; x++) {
			writeRAM(boardGetByte(x,y));
		}
		//Draw the other line
		for (byte x = 0; x < 16; x++) {
			writeRAM(boardGetByte(x,y+32));
		}
	}
}
inline byte LCD::boardGetByte(byte x, byte y) {
	return boardGetByte(byteCoordToIdx(x,y));
}
inline byte LCD::boardGetByte(int id) {
	return board[id];
}
inline void LCD::boardWriteByte(byte x, byte y, byte thing) {

}
void LCD::boardWriteByte(int id, byte thing) {

}
inline bool LCD::boardGetPixel(byte x, byte y) {

}
bool LCD::boardGetPixel(int id) {

}
inline void LCD::boardWritePixel(byte x, byte y, byte thing) {

}
void LCD::boardWritePixel(int id, byte thing) {

}

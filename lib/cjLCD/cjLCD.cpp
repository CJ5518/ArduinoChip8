#include "cjLCD.hpp"
#include "cjLCDFont.hpp"
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
	return byteCoordToIdx(x / 8, y);
}
inline void LCD::pixelIdxToCoord(int idx, byte* x, byte* y) {
	byteIdxToCoord(idx, x, y);
	*x *= 8;
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
	boardWriteByte(byteCoordToIdx(x,y), thing);
}
void LCD::boardWriteByte(int id, byte thing) {
	board[id] = thing;
}
inline bool LCD::boardGetPixel(byte x, byte y) {
	bitRead(board[pixelCoordToIdx(x,y)], x % 8);
}
inline void LCD::boardWritePixel(byte x, byte y, byte thing) {
	bitWrite(board[pixelCoordToIdx(x,y)], x % 8, thing);
}

byte bytereverse(byte b) {
  b = (b & 0x55) << 1 | (b & 0xAA) >> 1; // swap adjacent bits
  b = (b & 0x33) << 2 | (b & 0xCC) >> 2; // swap adjacent pairs
  b = (b & 0x0F) << 4 | (b & 0xF0) >> 4; // swap nibbles
  return b;
}

void LCD::drawChar(byte x, byte y, char thing) {
	for (byte yy = y; yy < y + 8; yy++) {
		
		boardWriteByte(x, yy, bytereverse(pgm_read_byte(font8x8_basic + ((int)thing*8) + (yy-y))));
	}
}
void LCD::drawString(byte x, byte y, char* thing) {
	byte count = 0;
	while (thing[count]) {
		drawChar(x + count, y, thing[count]);
		count++;
	}
}

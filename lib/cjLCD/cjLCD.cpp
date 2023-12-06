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
void LCD::writeRAMDoubledBits(byte data) {
	byte byte1, byte2;
	byte1 = 0;
	byte2 = 0;
	for (byte q = 0; q < 4; q++) {
		byte1 |= (bitRead(data, q) << (q*2));
		byte1 |= (bitRead(data, q) << ((q*2)+1));
	}
	for (byte q = 4; q < 8; q++) {
		byte2 |= (bitRead(data, q) << ((q-4)*2));
		byte2 |= (bitRead(data, q) << (((q-4)*2)+1));
	}
	writeRAM(byte2);
	writeRAM(byte1);
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
	return x + (y * 8);
}
inline void LCD::byteIdxToCoord(int idx, byte* x, byte* y) {
	*x = idx % 8;
	*y = (idx - *x) / 8;
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
		//Do it twice
		for (byte q = 0; q < 2; q++) {
			setGRAMAddress(0, y+q);
			//Draw one line
			for (byte x = 0; x < 8; x++) {
				writeRAMDoubledBits(boardGetByte(x,y/2));
			}
			//Draw the other line
			for (byte x = 0; x < 8; x++) {
				writeRAMDoubledBits(boardGetByte(x,(y/2)+16));
			}
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
bool LCD::boardGetPixel(byte x, byte y) {
	return bitRead(board[pixelCoordToIdx(x,y)], 7 - (x % 8));
}
void LCD::boardWritePixel(byte x, byte y, byte thing) {
	bitWrite(board[pixelCoordToIdx(x,y)], 7 - (x % 8), thing);
}

byte bytereverse(byte b) {
  b = (b & 0x55) << 1 | (b & 0xAA) >> 1; // swap adjacent bits
  b = (b & 0x33) << 2 | (b & 0xCC) >> 2; // swap adjacent pairs
  b = (b & 0x0F) << 4 | (b & 0xF0) >> 4; // swap nibbles
  return b;
}

void LCD::drawChars(byte x, byte y, char thing, char thing2) {
	if (thing2 == 0) thing2 = ' ';
	if (y >= 32) {
		y -= 32;
		x += 8;
	}
	for (byte yy = y; yy < y + 8; yy++) {
		setGRAMAddress(x, yy);
		writeRAM(bytereverse(pgm_read_byte(font8x8_basic + ((int)thing*8) + (yy-y))));
		writeRAM(bytereverse(pgm_read_byte(font8x8_basic + ((int)thing2*8) + (yy-y))));
	}
}
int LCD::drawString(byte x, byte y, char* thing) {
	byte count = 0;
	while (thing[count]) {
		drawChars(x + (count/2), y, thing[count], thing[count+1]);
		count+=2;
		if (thing[count-1] == 0) return count-1;
	}
	return count;
}

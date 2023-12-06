#ifndef CJ_LCD_HPP
#define CJ_LCD_HPP

#include <Arduino.h>

//Handles a 128 x 64 LCD
class LCD {
public:
	//Lower level functions
	void flipSclk();
	void sendBit(byte bit);
	void sendByte(byte rs, byte rw, byte thing);

	//Interface to commonly used functions
	void setDisplay(bool display, bool cursor, bool blink);
	void functionSet(bool extended, bool graphics = 1);
	void setGRAMAddress(byte x, byte y);
	void writeRAM(byte data);
	//Writes two bytes from just the 1
	void writeRAMDoubledBits(byte data);

	//High level 'board' interface
	byte board[256];
	inline int byteCoordToIdx(byte x, byte y);
	inline void byteIdxToCoord(int idx, byte* x, byte* y);
	inline int pixelCoordToIdx(byte x, byte y);
	inline void pixelIdxToCoord(int idx, byte* x, byte* y);
	void clearBoard();
	void drawBoard();
	inline byte boardGetByte(byte x, byte y);
	inline byte boardGetByte(int id);
	inline void boardWriteByte(byte x, byte y, byte thing);
	void boardWriteByte(int id, byte thing);
	bool boardGetPixel(byte x, byte y);
	void boardWritePixel(byte x, byte y, byte thing);

	//Font interface - all functions here take byte coordinates (so much easier)
	void drawChars(byte x, byte y, char thing, char thing2);
	int drawString(byte x, byte y, char* thing);


	//Initialization
	void init(byte CSbit, byte SCLKbit, byte SIDbit);
	LCD(byte CSbit, byte SCLKbit, byte SIDbit);
	LCD();

private:
	byte CS,SID,SCLK;
};

#endif

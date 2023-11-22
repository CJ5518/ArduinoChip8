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

	//Initialization
	void init(int CSbit, int SCLKbit, int SIDbit);
	LCD(int CSbit, int SCLKbit, int SIDbit);
	LCD();

private:
	int CS,SID,SCLK;
};

#endif

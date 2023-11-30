#ifndef CJ_KEYPAD_HPP
#define CJ_KEYPAD_HPP
#include "Arduino.h"

//Only works if all the keypad pins are hooked up to PORTD
class Keypad {
public:
	bool keypad[16];
	//Each of these arrays must be ordered properly, i.e rowPins[2] is indeed row 3
	//Please do that before calling init ok
	byte rowPins[4];
	byte colPins[4];


	void init();
	void updateState();
private:
	inline void clearKeypadState();
	byte decoderArray[16];
	//row and col are 0 indexed
	byte decodeKeypad(byte row, byte col);
};

#endif

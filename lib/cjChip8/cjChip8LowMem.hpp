#ifndef CJ_CHIP8_LOW_MEM
#define CJ_CHIP8_LOW_MEM

#include <Arduino.h>
#include "cjLCD.hpp"
#include "keypad.hpp"

#define MAX_MEMORY 1500
#define MAX_STACK 8

class Chip8 {
public:
	//Normally would have 8 times as much but desperate times call for desperate measures
	byte memory[MAX_MEMORY];
	uint16_t stack[MAX_STACK]; //Putting the stack here because it's easier
	//Number of items on stack
	byte stackPointer;
	uint16_t programCounter;
	uint16_t iRegister;
	byte registers[16];
	byte soundTimer;
	byte delayTimer;
	unsigned long instructionsExecuted;
	//A number that means different things depending on the exception
	unsigned long exceptionInfo;
	unsigned long exceptionInfo2;

	//Flags in case of problems, will be non-zero if anything went wrong
	byte exceptionFlags;
	//The possible problems
	const byte UNKNOWN_OPCODE = 1;
	const byte NO_MEMORY = 1 << 1;
	const byte STACK_OVERFLOW = 1 << 2;
	const byte STACK_UNDERFLOW = 1 << 3;
	const byte BAD_LCD_COORDS = 1 << 4;

	LCD* lcd;
	Keypad* keypad;


	void loadROM(const byte* data, int length);
	void tick();
};

#endif

#ifndef CJ_CHIP8_LOW_MEM
#define CJ_CHIP8_LOW_MEM

#include <Arduino.h>

class Chip8 {
	//Normally would have 8 times as much but desperate times call for desperate measures
	byte memory[512];
	uint16_t instructionPointer;
	byte registers[16];
	uint16_t stack[12]; //Putting the stack here because it's easier
	byte soundTimer;
	byte delayTimer;
};

#endif

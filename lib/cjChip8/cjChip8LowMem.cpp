#include <Arduino.h>
#include "cjChip8LowMem.hpp"


const PROGMEM byte chip8Font[] = {
0xf0, 0x90, 0x90, 0x90, 0xf0, // 0
0x20, 0x60, 0x20, 0x20, 0x70, // 1
0xf0, 0x10, 0xf0, 0x80, 0xf0, // 2
0xf0, 0x10, 0xf0, 0x10, 0xf0, // 3
0x90, 0x90, 0xf0, 0x10, 0x10, // 4
0xf0, 0x80, 0xf0, 0x10, 0xf0, // 5
0xf0, 0x80, 0xf0, 0x90, 0xf0, // 6
0xf0, 0x10, 0x20, 0x40, 0x40, // 7
0xf0, 0x90, 0xf0, 0x90, 0xf0, // 8
0xf0, 0x90, 0xf0, 0x10, 0xf0, // 9
0xf0, 0x90, 0xf0, 0x90, 0x90, // A
0xe0, 0x90, 0xe0, 0x90, 0xe0, // B
0xf0, 0x80, 0x80, 0x80, 0xf0, // C
0xe0, 0x90, 0x90, 0x90, 0xe0, // D
0xf0, 0x80, 0xf0, 0x80, 0xf0, // E
0xf0, 0x80, 0xf0, 0x80, 0x80};// F

void Chip8::loadROM(const byte* data, int length) {
	if (length + PGM_OFFSET_POSITIVE >= MAX_MEMORY) {
		exceptionFlags |= NO_MEMORY;
		exceptionInfo = 1;
		exceptionInfo2 = length;
		return;
	}
	for (int q = 0; q < length; q++) {
		memory[q+PGM_OFFSET_POSITIVE] = pgm_read_byte(data + q);
	}
	programCounter = PGM_OFFSET_POSITIVE;
	stackPointer = 0;
	exceptionFlags = 0;
	instructionsExecuted = 0;
	exceptionInfo = 0;
	exceptionInfo2 = 0;
	iPointsToFontData = false;
}
void Chip8::tick() {
	if (programCounter >= MAX_MEMORY) {
		exceptionFlags |= NO_MEMORY;
		exceptionInfo = 2;
		exceptionInfo2 = programCounter;
		return;
	}
	byte opcodeHi = memory[programCounter];
	byte opcodeLo = memory[programCounter + 1];

	byte X = opcodeHi & 0x0F;
	byte Y = opcodeLo >> 4;
	uint16_t opcode = (opcodeHi << 8) | opcodeLo;
	uint16_t NNN = opcode & 0x0FFF;
	uint16_t NN = opcode & 0xFF;

	programCounter += 2;

	switch (0xF0 & opcodeHi) {
		case 0x00: {
			switch (opcodeLo) {
				case 0xE0: { //Clear screen
					lcd->clearBoard();
				} break;
				case 0xEE: { //Return from subroutine
					stackPointer--;
					if (stackPointer >= 0) {
						programCounter = stack[stackPointer];
					} else {
						exceptionFlags |= STACK_UNDERFLOW;
					}
				} break;
				default: {
					exceptionFlags |= UNKNOWN_OPCODE;
				} break;
			}
		} break;
		case 0x10: { //Goto
			programCounter = NNN - PGM_OFFSET; //Always sub PGM_OFFSET because our mem starts at 0
		} break;
		case 0x20: { //Call subroutine
			if (stackPointer < MAX_STACK) {
				stack[stackPointer] = programCounter;
				stackPointer++;
				programCounter = NNN - PGM_OFFSET; //Always sub PGM_OFFSET because our mem starts at 0
			} else {
				exceptionFlags |= STACK_OVERFLOW;
			}
		} break;
		case 0x30: { // if VX == NN
			if (registers[X] == NN) {
				programCounter += 2;
			}
		} break;
		case 0x40: { //Same as above but !=
			if (registers[X] != NN) {
				programCounter += 2;
			}
		} break;
		case 0x50: { //Same as 0x30 but two registers
			if (registers[X] == registers[Y]) {
				programCounter += 2;
			}
		} break;
		case 0x60: { //Register load
			registers[X] = NN;
		} break;
		case 0x70: { //No carry flag ADD
			registers[X] += NN;
		} break;
		case 0x80: {
			//Mathematics
			switch (0x0F & opcodeLo) {
				case 0: { //Register assignment
					registers[X] = registers[Y];
				} break;
				case 1: { //Register OR 
					registers[X] |= registers[Y];
				} break;
				case 2: { //Register AND
					registers[X] &= registers[Y];
				} break;
				case 3: { //Register XOR
					registers[X] ^= registers[Y];
				} break;
				case 4: { //Register addition with carry
					if (registers[Y] > 0xFF - registers[X]) {
						registers[0xF] = 1;
					} else {
						registers[0xF] = 0;
					}
					registers[X] += registers[Y];
				} break;
				case 5: { //Register subtraction with carry
					if (registers[Y] > registers[X]) {
						registers[0xF] = 1;
					} else {
						registers[0xF] = 0;
					}
					registers[X] -= registers[Y];
				} break;
				case 6: { //Bitshift right
					registers[0xF] = bitRead(registers[X], 0);
					registers[X] >>= 1;
				} break;
				case 7: { //Sets VX to VY minus VX with carry
					if (registers[X] > registers[Y]) {
						registers[0xF] = 1;
					} else {
						registers[0xF] = 0;
					}
					registers[X] = registers[Y] - registers[X];
				} break;
				case 0xE: { //Bitshift left
					registers[0xF] = bitRead(registers[X], 7);
					registers[X] <<= 1;
				} break;
				default: {
					exceptionFlags |= UNKNOWN_OPCODE;
				} break;
			}
		} break;
		case 0x90: { //registers not equal
			if (registers[X] != registers[Y]) {
				programCounter += 2;
			}
		} break;
		case 0xA0: {
			iRegister = NNN - PGM_OFFSET; //Always sub the PGM_OFFSET
			iPointsToFontData = false;
		} break;
		case 0xB0: { //Jumps to the address NNN plus V0
			programCounter = registers[0] + (NNN - PGM_OFFSET);
		} break;
		case 0xC0: { //Random numbers
			registers[X] = NN & (rand() % 256);
		} break;
		case 0xD0: { //Draw a sprite
			if ((iRegister + (opcodeLo & 0x0F)) >= MAX_MEMORY) {
				exceptionFlags |= NO_MEMORY;
				exceptionInfo = 3;
				exceptionInfo2 = iRegister;
				return;
			}

			for (byte col = 0; col < (opcodeLo & 0x0F); col++) {
				byte row;
				if (iPointsToFontData) {
					row = pgm_read_byte(chip8Font + (iRegister * 5) + col);
				} else {
					row = memory[iRegister + col];
				}
				for (byte q = 0; q < 8; q++) {
					if (row & 0x80) {
						byte reqX = (registers[X] + q) % 64;
						byte reqY = (registers[Y] + col) % 32;
						bool oldState = lcd->boardGetPixel(reqX, reqY);
						byte toWrite = !oldState;
						if (oldState) {
							registers[0xF] = 1;
						}
						
						lcd->boardWritePixel(reqX, reqY, toWrite);
					}
					row <<= 1;
				}
			}
			iPointsToFontData = false;
		} break;
		case 0xE0: { //User input
			switch (opcodeLo) {
				case 0x9E: {
					if (keypad->keypad[registers[X]]) {
						programCounter += 2;
					}
				} break;
				case 0xA1: {
					if (!keypad->keypad[registers[X]]) {
						programCounter += 2;
					}
				} break;
				default: {
					exceptionFlags |= UNKNOWN_OPCODE;
				} break;
			}
		} break;
		case 0xF0: { //Misc
			switch (opcodeLo) {
				case 0x07: { //Sets VX to the value of the delay timer.
					registers[X] = delayTimer;
				} break;
				case 0x0A: { //A key press is awaited, and then stored in VX
					while (true) {
						keypad->updateState();
						for (int q = 0; q < 16; q++) {
							if (keypad->keypad[q]) {
								registers[X] = q;
								break;
							}
						}
					}
				} break;
				case 0x15: { //	Sets the delay timer to VX.
					delayTimer = registers[X];
				} break;
				case 0x18: { //	Sets the sound timer to VX.
					soundTimer = registers[X];
				} break;
				case 0x1E: { //Adds VX to I
					iRegister += registers[X];
				} break;
				case 0x29: { //Sets I to the location of the sprite for the character in VX
					//We treat this one in a silly manner
					//Set a flag that I points to a character
					iPointsToFontData = true;
					iRegister = registers[X];
				} break;
				case 0x33: { //BCD
					if (iRegister + 2 >= MAX_MEMORY) {
						exceptionFlags |= NO_MEMORY;
						exceptionInfo = 4;
						exceptionInfo2 = iRegister;
						return;
					}
					byte value = registers[X];
					memory[iRegister + 2] = value % 10;

					value /= 10;
					memory[iRegister + 1] = value % 10;

					value /= 10;
					memory[iRegister + 0] = value % 10;
				} break;
				case 0x55: { //Stores from V0 to VX (including VX) in memory, starting at address I
					if (iRegister + X >= MAX_MEMORY) {
						exceptionFlags |= NO_MEMORY;
						exceptionInfo = 5;
						exceptionInfo2 = iRegister;
						return;
					}
					for (byte q = 0; q <= X; q++) {
						memory[iRegister + q] = registers[q];
					}
				} break;
				case 0x65: { //Fills from V0 to VX (including VX) with values from memory, starting at address I
					if (iRegister + X >= MAX_MEMORY) { 
						exceptionFlags |= NO_MEMORY;
						exceptionInfo = 6;
						exceptionInfo2 = iRegister;
						return;
					}
					for (byte q = 0; q <= X; q++) {
						registers[q] = memory[iRegister + q];
					}
				} break;
				default: {
					exceptionFlags |= UNKNOWN_OPCODE;
				} break;
			}
		} break;
	}
	instructionsExecuted++;
}


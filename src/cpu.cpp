
#include "shared.hh"

uint_8 registers[8];
uint_8 flag_register = 0x0000;

// 0xC3 + LSB of nn + MSB of nn
// 3 bytes
// JP nn Unconditional jump to absolute address specified by operand nn
void UnconditionalJump(uint_8 instruction) 
{


}

// 0xE9
// 1 byte
// JP HL Unconditional jump to the absolute address specified by the register HL
void UnconditionalJumpToHL(uint_8 instruction) 
{


}


// 0xC2 -> 110cc010 + LSB of nn + MSB of nn
// 3 bytes
// JP cc, nn Conditional jump to the absolute address specified by the operand nn.
// depending on condition cc.
void ConditionalJumpCompareCC(uint_8 instruction) 
{

	if (instruction ^ 0xC2) {
	

	
	}

}

// 0x18 offset r
// 2 bytes
// JR r Unconditional jump to relative address specified by the signed operand r
void UnconditionalJumpToSignedR(uint_8 instruction) 
{



}

// 0x20 -> 001cc000 + offset r
// 2 bytes
// Conditional jump to the relative address specified by the signed operand r,
// depending on the condition cc. Mem_pointer = Mem_pointer + r
void ConditionalJumpWithOffsetR(uint_8 instruction) 
{

	if (instruction ^ 0x20) {
	
	
	}

}

// 0xCD + LSB of nn + MSB of nn
// 3 bytes
// Call nn Unconditional function call to the absolute address specified by operand nn
void UnconditionalCallToNN(uint_8 instruction) 
{



}

// 0xC4 + LSB of nn + MSB of nn
// 3 bytes
// Call cc, nn Conditional jump to operand nn if cc is true
void ConditionalCallToNN(uint_8 instruction) 
{

	if (instruction ^ 0xC4) {
	
	
	}

}

// 0xC9
// 1 byte
// Return
void Return(uint_8 instruction) 
{



}

// 0xC0 -> 110cc000
// 1 byte
// RET cc Conditional return from functions, depending on the condition cc.
void ConditionalReturn(uint_8 instruction) 
{

	if (instruction ^ 0xC0) {
	
	
	}

}

// 0xD9
// 1 byte
// RETI Unconditional return from function. Also enables interrupts by setting IME=1
void UnconditionalReturnI(uint_8 instruction) 
{



}

// 0xC7 -> 11xxx111
// 1 byte
// RST n Unconditional function call to the absolute fixed address xxx
void UnconditionalCallFromOpcode(uint_8 instruction) 
{

	if (instruction ^ 0xC7) {
	
	}

}

// 0xF3
// 1 byte
// HALT, STOP, DI Disables interrupt handling by setting IME=0 and cancelling any
// scheduled effects of the EI instruction if any.
void Stop(uint_8 instruction) 
{

	

}

// 0xFB
// 1 byte
// EI
// Schedules interrupt handling to be enabled after the next machine cycle
void ScheduleIME(uint_8 instruction) 
{


}

// 0x3F
// 1 byte
// CCF
// Flips the carry flag, clears the N and H flags
void CCF(uint_8 instruction) 
{

	flag_register ^= 0x10;
	flag_register &= 0xDF;
	flag_register &= 0xBF;

}

// 0x37
// 1 byte
// SCF
// Sets the carry flag, and clears the N and H flags
void SCF(uint_8 instruction) 
{

	flag_register |= 0x10;
    flag_register &= 0xDF;
    flag_register &= 0xBF;

}

// 0x00
// 1 byte
// NOP
// No-operation
void NOP(uint_8 instruction) 
{


}

// DAA missing documentation
// 1 byte
//
void DAA(uint_8 instruction) 
{

}

// 0x2F
// 1 byte
// Flips all the bits in register A and sets the N and H Flags
void CPL(uint_8 instruction) 
{

	registers[0] ^= 0xFF;

}

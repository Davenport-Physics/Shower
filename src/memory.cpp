
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include "memory.hh"
#include "shared.hh"

#define MAX_CARTRIDGE_SIZE 8388608

char name[17]; 
uint_16 memory_pointer = 0x0100;
uint_16 stack_pointer  = 0xFFFE;
uint_8 *cartridge_memory;
uint_8 *memory;

CartridgeType cartridge;
GameboyType gameboy;

void InitCartridgeMemory(char *cartridge) 
{

	cartridge_memory = new uint_8[MAX_CARTRIDGE_SIZE];
	memset(cartridge_memory, 0, MAX_CARTRIDGE_SIZE);

}

void LoadCartridge(char *cartridge) 
{

	InitCartridgeMemory(cartridge);

	std::ifstream cartridge_file_handle;
	cartridge_file_handle.open(cartridge, std::ifstream::in | std::ifstream::binary);

	long idx = 0;
	uint_8 c;
	while (!cartridge_file_handle.eof()) {
	
		cartridge_memory[idx] = cartridge_file_handle.get();
		idx++;

	}
	cartridge_file_handle.close();

}

void ParseGameboyType() 
{

	if (cartridge_memory[0x0143] == 0x80)
		gameboy = GAMEBOY_COLOR;		
	else
		gameboy = GAMEBOY;

}
void ParseCartridgeType()
{

	cartridge = (CartridgeType)cartridge_memory[0x0147];

}

void ParseGameName() 
{

	for (size_t i = 0x0134; i < 0x0143;i++) {

		name[i - 0x0134] = cartridge_memory[i];	
	
	}
	name[16] = {'\0'};
	printf("cart name = %s\n", name);

}

void SetGameInfo() 
{

	ParseGameboyType();
	ParseCartridgeType();
	ParseGameName();

}

void SetRamBank0() 
{

	for (size_t i = 0; i < 0x4000; i++) {
	
		memory[i] = cartridge_memory[i];
	
	}

}

void SetRamBankn(int bank) 
{

	int bank_idx = (bank - 1) * 0x4000;
	for (size_t i = 0x4000; i < 0x8000;i++) {
	
		memory[i] = cartridge_memory[bank_idx];
		bank_idx++;

	}

}

void SetMemory() 
{
	
	int memory_model = 0;

	if (gameboy == GAMEBOY) {
	
		memory_model = 0xFFFF;
		memory       = new uint_8[0xFFFF];
		printf("GAMEBOY cartridge memory set\n");

	} else {
	
		// TODO reserved for GAMEBOY_COLOR

	}

	memset(memory, 0, memory_model);
	SetRamBank0();

}

void InitMemory(char *cartridge)
{

	LoadCartridge(cartridge);
	SetGameInfo();
	SetMemory();	

}

void ExitMemory() 
{

	delete [] cartridge_memory;
	delete [] memory;

}

uint_8 GetValueAtAddress(long address) 
{

	return memory[address];

}

uint_8 GetNextMemoryValue() 
{

	uint_8 instruction = memory[memory_pointer];
	memory_pointer++;

	return instruction;

}


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include "memory.hh"
#include "shared.hh"

#define MAX_CARTRIDGE_SIZE 8388608

char name[17]; 
long cartridge_size;
uint_8 *cartridge_memory;

CartridgeType cartridge;
GameboyType gameboy;

long GetFileSize(char *cartridge) 
{
	// TODO or maybe not?
	// Value obtained is different than the amount of bytes read.

	FILE *fp = fopen(cartridge, "rb");
	
	if (fp == NULL) {
	
		printf("Unable to open %s\n", cartridge);
		exit(0);

	}

	fseek(fp, 0, SEEK_END);

	unsigned long filesize = ftell(fp);
	fclose(fp);

	printf("detected catridge file size = %d bytes\n", filesize);

	return filesize;

}

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

}

void SetGameInfo() 
{

	ParseGameboyType();
	ParseCartridgeType();
	ParseGameName();

}

void SetMemory() 
{


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

}

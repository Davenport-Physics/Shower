
#include <cstdio>

#include "memory.hh"

char name[17];
unsigned char *cartridge_memory;

CartridgeType cartridge;
GameboyType gameboy;

long int GetFileSize(char *cartridge) 
{

	FILE *fp = fopen(cartridge, "rb");
	fseek(fp, 0, SEEK_END);

	long int filesize = ftell(fp);
	fclose(fp);

	return filesize;

}

void InitCartridgeMemory(char *cartridge) 
{

	cartridge_memory = new unsigned char[GetFileSize(cartridge)];

}

void LoadCartridge(char *cartridge) 
{

	InitCartridgeMemory(cartridge);

	FILE *fp = fopen(cartridge, "rb");
	unsigned int idx = 0;
	unsigned char c;
	while ((c = getc(fp)) != EOF) {
	
		cartridge_memory[idx] = c;
		idx++;
	
	}

	fclose(fp);

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

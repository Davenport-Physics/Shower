#ifndef MEMORY_HH
#define MEMORY_HH

#include "shared.hh"

typedef enum CartridgeType 
{

	ROM                   = 0x00,
	ROM_MBC1              = 0x01,
	ROM_MBC1_RAM          = 0x02,
	ROM_MBC1_RAM_BAT      = 0x03,
	ROM_MBC2              = 0x05,
	ROM_MBC2_BAT          = 0x06,
	ROM_RAM               = 0x08,
	ROM_RAM_BAT           = 0x09,
	ROM_MMM01             = 0x0B,
	ROM_MMM01_SRAM        = 0x0C,
	ROM_MMM01_SRAM_BAT    = 0x0D,
	ROM_MBC3_RAM          = 0x12,
	ROM_MBC3_RAM_BAT      = 0x13,
	ROM_MBC5              = 0x19,
	ROM_MBC5_RAM          = 0x1A,
	ROM_MBC5_RAM_BAT      = 0x1B,
	ROM_MBC5_RUM          = 0x1C,
	ROM_MBC5_RUM_SRAM     = 0x1D,
	ROM_MBC5_RUM_SRAM_BAT = 0x1E,
	POCKET_CAMERA         = 0x1F,
	BANDAI_TAMA5          = 0xFD,
	HUDSON_HUC            = 0xFE

} CartridgeType;

typedef enum GameboyType {

	GAMEBOY,
	GAMEBOY_COLOR

} GameboyType;

void InitMemory(char *cartridge);
void ExitMemory();

uint_8 GetValueAtAddress(long address);
uint_8 GetNextMemoryValue();

void Jump(uint_16);
void CallFunction(uint_16);

#endif

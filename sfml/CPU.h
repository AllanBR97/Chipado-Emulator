#pragma once
#include "CPU.h"

#include <cstdint>

#define MEM 4096

/// <summary>
/// Represents Chip-8 CPU
/// </summary>
struct CPU
{
	uint8_t memory[MEM]; // 4Kb is total memory
	uint8_t Vx[16]; // General purpose V0 - VF
	uint8_t SP; // Stack pointer
	uint8_t DL; // Delay timer
	uint8_t ST; // Sound timer
	uint8_t display[64][32]; // display

	int16_t I; // Store address memory
	int16_t PC; // Program counter
	int16_t Stack[16]; // Stack
	bool VF; // Flag for opcodes
};

// CPU initialization
CPU* init_cpu(void);

/// <summary>
/// Loads a ROM image into CPU memory
/// </summary>
/// <param name="cpu">: A CPU pointer</param>
/// <param name="cFilename">: ROM location</param>
/// <param name="bIsETI">: true if ETI is on, false otherwise</param>
void load_rom(CPU* cpu, const char* cFilename, bool bIsETI);

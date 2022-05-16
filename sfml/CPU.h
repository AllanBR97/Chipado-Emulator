#pragma once
#include "CPU.h"

typedef unsigned char byte; // Represents 1 byte

/// <summary>
/// Represents Chip-8 CPU
/// </summary>
struct CPU
{
	byte memory[4096]; // 4Kb is total memory
};

struct CPU* init_cpu(void);

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>

#include "CPU.h"

CPU* init_cpu()
{
	uint8_t font[16][5] = {
	{0xF0, 0x90, 0x90, 0x90, 0xF0}, // 0
	{0x20, 0x60, 0x20, 0x20, 0x70}, // 1
	{0xF0, 0x10, 0xf0, 0x80, 0xF0}, // 2
	{0xF0, 0x10, 0xF0, 0x10, 0xF0}, // 3
	{0x90, 0x90, 0xF0, 0x10, 0x10}, // 4
	{0xF0, 0x80, 0xF0, 0x10, 0xF0}, // 5
	{0xF0, 0x80, 0xF0, 0x90, 0xF0}, // 6
	{0xF0, 0x10, 0x20, 0x40, 0x40}, // 7
	{0xF0, 0x90, 0xF0, 0x90, 0xF0}, // 8
	{0xF0, 0x90, 0xF0, 0x10, 0xF0}, // 9
	{0xF0, 0x90, 0xF0, 0x90, 0x90}, // A
	{0xE0, 0x90, 0xE0, 0x90, 0xE0}, // B
	{0xF0, 0x80, 0x80, 0x80, 0xF0}, // C
	{0xE0, 0x90, 0x90, 0x90, 0xE0}, // D
	{0xF0, 0x80, 0xF0, 0x80, 0xF0}, // E
	{0xF0, 0x80, 0xF0, 0x80, 0x80} //  F
	}; // Font used to be drawn

	CPU* cpu = (CPU*) malloc(sizeof(CPU));
	if (cpu != nullptr)
	{
		memset(cpu, 0, sizeof(CPU));
		if (!memcpy_s(cpu->memory, MEM, font, sizeof(font)))
		{
			printf("MEM: %d\n", *(cpu->memory));
		}
	}
	
	return cpu;
}

void load_rom(CPU *cpu, const char *cFilename, bool bIsETI)
{
	if (cpu == nullptr)
	{
		puts("NULL reference");
		return;
	}

	int iStartAddress = 0;
	if (bIsETI)
	{
		iStartAddress = 0x600;
	}
	else
	{
		iStartAddress = 0x200;
	}

	FILE* file;
	uint8_t buffer[MEM];

	if (!fopen_s(&file, cFilename, "r"))
	{
		size_t tam = fread_s(buffer, MEM, sizeof(uint8_t), MEM / sizeof(uint8_t), file);
		printf("File size: %zd\n", tam);
		printf("Opened %s\n", cFilename);

		if (!memcpy_s(cpu->memory + iStartAddress, MEM, buffer, tam))
		{
			printf("%x %x", cpu->memory[513], cpu->memory[514]);
			//printf("%d %d\n", *(cpu->memory + iStartAddress), *(cpu->memory + iStartAddress + 1));
		}
		
		fclose(file);
	}
}
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>

#include "CPU.h"

CPU* init_cpu()
{
	CPU* cpu = (CPU*) malloc(sizeof(CPU));
	if (cpu != nullptr)
	{
		memset(cpu, 0, sizeof(CPU));
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
	int tam = 0;

	if (!fopen_s(&file, cFilename, "r"))
	{
		tam = (int) fread_s(buffer, MEM, sizeof(uint8_t), MEM / sizeof(uint8_t), file);
		printf("File size : %ld\n", tam);
		printf("Opened %s\n", cFilename);

		if (!memcpy_s(cpu->memory + iStartAddress, MEM, buffer, tam))
		{
			printf("%x %x", cpu->memory[513], cpu->memory[514]);
			//printf("%d %d\n", *(cpu->memory + iStartAddress), *(cpu->memory + iStartAddress + 1));
		}
		
		fclose(file);
	}
}
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "CPU.h"

int main(int argc, char *argv[])
{
	CPU* cpu = init_cpu();
	load_rom(cpu, "C:\\Users\\allan\\Downloads\\IBM Logo.ch8", false);
	free(cpu);
    return 0;
}

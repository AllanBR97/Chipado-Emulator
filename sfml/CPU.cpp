#include "CPU.h"
#include <cstdlib>
#include <cstdio>

CPU* init_cpu()
{
	struct CPU* cpu = (struct CPU*) malloc(sizeof(struct CPU));
	return cpu;
}
#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "CPU.h"

void help_command()
{
	puts("Chipado, a Brazilian Chip-8 emulator\n");
	puts("/h = this message");
	puts("/l = load Chip-8 file\n");
	puts("Made in C by Marmota - 2022");
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		help_command();
		return 0;
	}

	for (size_t i = 0; i < argc; i++)
	{
		printf("args[%zd] = %s\n", i, argv[i]);

		if (!strcmp(argv[i], "/h"))
		{
			help_command();
		}
	}
    return 0;
}

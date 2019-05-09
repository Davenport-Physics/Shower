#include <cstdio>
#include <cstdlib>

#include "memory.hh"

void InitMemoryIfPossible(int argc, char **argv) 
{

	if (argc > 1) {
	
		InitMemory(argv[1]);

	} else {
	
		printf("Did not pass a file name\n");
		exit(0);

	}
		

}

void InitShower(int argc, char **argv) 
{

	InitMemoryIfPossible(argc, argv);

}

int main(int argc, char **argv) 
{

	InitShower(argc, argv);

	return 0;

}

#include <time.h>
//#include <stdio.h>
#include "types.h"
#include "bees.h"
#include "bestBee.h"
#include "bestPosition.h"
#include "printBees.h"

clock_t start()
{
	return clock();
}

void finish(clock_t begin)
{
	clock_t end = clock();
	printf("Time: %f sec\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

void chooseBestEmployed(Bees bees)
{
	int i;
	for (i=NUMBER_OF_ONLOOKER; i<SN; i++)
	{
		onlookerPlacement(bees, i);
		printBees(bees);
	}
}

int main()
{
	clock_t begin;
	int i, cycles;
	Bees bees = (Bees) malloc(sizeof (struct bees));
	BestBee bestBee = (BestBee) malloc(sizeof (struct bestBee));
	
	begin = start();
	setInizializedFalse(bestBee);
	initializeType(bees);
	srand(time(0));

	initializeType(bees);
	for (i=0; i<NUMBER_OF_EMPLOYED; i++)
		employedPlacement(bees, i);

	for (cycles=0; cycles<MAX_CYCLES; cycles++) 
	{
		chooseBestEmployed(bees);
		foodExploitation(bees, i);
		printBees(bees);
		saveBestPosition(bestBee, bees);
	}

	printBestBee(bestBee);

	finish(begin);
	free(bees);
	free(bestBee);
	system("PAUSE");
	return 0;
}
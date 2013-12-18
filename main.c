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

void assignEmployed(Bees bees)
{
	int i;
	for (i=NUMBER_OF_ONLOOKER; i<SN; i++)
	{
		onlookerPlacement(bees, i);
		dprintf("ONLOOKER PLACEMENT %d\n", i);
		printBees(bees);
	}
	for (i=0; i<SN; i++)
	{
		foodExploitation(bees, i);
		dprintf("GOOD EXPLOITATION %d\n", i);
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
	srand(time(0));

	setInizializedFalse(bestBee);
	initializeType(bees);
	for (i=0; i<NUMBER_OF_EMPLOYED; i++)
		employedPlacement(bees, i);

	for (cycles=0; cycles<MAX_CYCLES; cycles++) 
	{
		assignEmployed(bees);
		//printBees(bees);
		saveBestPosition(bestBee, bees);
		printBestBee(bestBee);
	}

	printBestBee(bestBee);

	finish(begin);
	free(bees);
	free(bestBee);
	system("PAUSE");
	return 0;
}
#include <time.h>
//#include <stdio.h>
#include "types.h"
#include "bees.h"
#include "bestBee.h"
#include "bestPosition.h"
#include "printBees.h"

void chooseBestEmployed(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
	{
		onlookerPlacement(bees, i);
		printBees(bees);
	}
}

int main()
{
	int i, cycles;
	Bees bees = (Bees) malloc(sizeof (struct bees));
	BestBee bestBee = (BestBee) malloc(sizeof (struct bestBee));
	setInizializedFalse(bestBee);
	srand(time(0));

	initializeBees(bees);
	for (i=0; i<D; i++)
		employedPlacement(bees, i);

	for (cycles=0; cycles<MAX_CYCLES; cycles++) 
	{
		chooseBestEmployed(bees);
		foodExploitation(bees, i);
		printBees(bees);
		saveBestPosition(bestBee, bees);
	}

	printBestBee(bestBee);

	free(bees);
	free(bestBee);
	system("PAUSE");
	return 0;
}
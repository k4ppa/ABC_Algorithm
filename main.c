#include <time.h>
//#include <stdio.h>
#include "bees.h"
#include "bestBee.h"
#include "types.h"

void beesSearch(Bees bees);
void saveBestPosition(BestBee bestBee, Bees bees);
	BOOL isBeePositionBetter(BestBee bestBee, Bees bees, int i);
	void replaceBestPosition(BestBee bestBee, Bees bees, int i);

void beesSearch(Bees bees)
{
	int i;
	for (i=0; i<D; i++)
	{
		onlookerPlacement(bees, i);
		foodExploitation(bees, i);
	}
}

void saveBestPosition(BestBee bestBee, Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
	{
		if (isBeePositionBetter(bestBee, bees, i))
			replaceBestPosition(bestBee, bees, i);
	}
}

	BOOL isBeePositionBetter(BestBee bestBee, Bees bees, int i)
	{
		return getBestFitness(bestBee) > getFitness(bees, i);
	}

	void replaceBestPosition(BestBee bestBee, Bees bees, int i)
	{
		setBestPosition(bestBee, getPosition(bees, i));
		setBestFitness(bestBee, getFitness(bees, i));
	}

int main()
{
	Bees bees = (Bees) malloc(sizeof (struct bees));
	BestBee bestBee = (BestBee) malloc(sizeof (struct bestBee));
	int i, cycles;

	srand(time(0));

	initializeBees(bees);
	for (i=0; i<D; i++)
		employedPlacement(bees, i);

	for (cycles=0; cycles<MAX_CYCLES; cycles++) 
	{
		beesSearch(bees);
		saveBestPosition(bestBee, bees);
	}

	free(bees);
	free(bestBee);
	system("PAUSE");
	return 0;
}
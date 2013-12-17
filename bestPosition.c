#include "bestPosition.h"

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

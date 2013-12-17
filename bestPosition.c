#include "bestPosition.h"

void saveBestPosition(BestBee bestBee, Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
	{
		if (isAlreadyInizialized(bestBee))
		{
			if (isBeePositionBetter(bestBee, bees, i))
				replaceBestPosition(bestBee, bees, i);
		}
		else
		{
			replaceBestPosition(bestBee, bees, i);
			setInizializedTrue(bestBee);
		}
	}
}

	BOOL isAlreadyInizialized(BestBee bestBee)
	{
		return getInizialized(bestBee) == TRUE;
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

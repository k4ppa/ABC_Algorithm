#include "bestBee.h"

#if DEBUG == ENABLED
#include <stdio.h>
#endif

void setBestFitness(BestBee bestBee, double newBestFitness)
{
	bestBee->bestFitness = newBestFitness;
}

double getBestFitness(BestBee bestBee)
{
	return bestBee->bestFitness;
}

void setBestPosition(BestBee bestBee, double newBestPosition[])
{
	int i;
	for (i=0; i<D; i++) 
		bestBee->bestPosition[i] = newBestPosition[i];
}

double *getBestPosition(BestBee bestBee)
{
	return bestBee->bestPosition;
}


void setInizializedTrue(BestBee bestBee)
{
	bestBee->inizialized = TRUE;
}

void setInizializedFalse(BestBee bestBee)
{
	bestBee->inizialized = FALSE;
}

BOOL getInizialized(BestBee bestBee)
{
	return bestBee->inizialized;
}

#include "bestBee.h"

void setBestFitness(BestBee bestBee, float newBestFitness)
{
	bestBee->bestFitness = newBestFitness;
}

float getBestFitness(BestBee bestBee)
{
	return bestBee->bestFitness;
}

void setBestPosition(BestBee bestBee, float newBestPosition[])
{
	int i;
	for (i=0; i<D; i++)
		bestBee->bestPosition[i] = newBestPosition[i];
}

float *getBestPosition(BestBee bestBee)
{
	return bestBee->bestPosition;
}


#include "bees.h"

void setType(Bees bees, int i, unsigned int newType)
{
	setBits(&bees.type[i], newType);
}

unsigned int getType(Bees bees, int i)
{
	return getBits(&bees.type[i]);
}

void setTrial(Bees bees, int i, int newTrial)
{
	bees.trial[i] = newTrial;
}

int getTrial(Bees bees, int i)
{
	return bees.trial[i];
}

void setFitness(Bees bees, int i, float newFitness)
{
	bees.fitness[i] = newFitness;
}

float getFitness(Bees bees, int i)
{
	return bees.fitness[i];
}
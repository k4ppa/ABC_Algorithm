#include "bees.h"

void setType(Bees bees, int i, unsigned int newType)
{
	setBits(&bees->type[i], newType);
}

unsigned int getType(Bees bees, int i)
{
	return getBits(&bees->type[i]);
}

void setTrial(Bees bees, int i, int newTrial)
{
	bees->trial[i] = newTrial;
}

int getTrial(Bees bees, int i)
{
	return bees->trial[i];
}

void setFitness(Bees bees, int i, double newFitness)
{
	bees->fitness[i] = newFitness;
}

double getFitness(Bees bees, int i)
{
	return bees->fitness[i];
}

void setP(Bees bees, int i, double newP)
{
	bees->p[i] = newP;
}

double getP(Bees bees, int i)
{
	return bees->p[i];
}

void setPosition(Bees bees, int i, double newPosition[])
{
	int y;
	for (y=0; y<D; y++)
		bees->positions[i][y] = newPosition[y];
}

double *getPosition(Bees bees, int i)
{
	return bees->positions[i];
}

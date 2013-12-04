#include "bees.h"

void initializeBees(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
		setBee(bees, i);
}

	void setBee(Bees bees, int i)
	{
		chooseBeeType(bees, i);
		bees.trial[i] = 0;
		bees.p[i] = 0.0;
	}

		void chooseBeeType(Bees bees, int i)
		{
			if (i <= NUMBER_OF_EMPLOYED)
				setType(bees, i, EMPLOYED);
			else
				setType(bees, i, UNASSIGNED_ONLOOKER);
		}



void employedPlacement(Bees bees, int i)
{
	if (isEmployed(bees, i))
		generateNewBeePosition(bees.positions[i]);
		//evaluateFitness(bees.positions[i]);
		setTrial(bees, i, 0);
}
	
	BOOL isEmployed(Bees bees, int i)
	{
		return getType(bees, i) == EMPLOYED;
	}

	void generateNewBeePosition(float position[])
	{
		int y;
		for (y=0; y<D; y++)
			position[y] = chooseRandomValueBetweenRange();
	}

		float chooseRandomValueBetweenRange()
		{
			float random = ((float) rand()) / (float) RAND_MAX;
			float range = MAX_SEARCH_RANGE - MIN_SEARCH_RANGE;
			return MIN_SEARCH_RANGE + (random * range);
		}

	/*evaluateFitness()
	{
	}*/
			

void onLookerPlacement(Bees bees, int i)
{
	//genera distribuzione probabilità
	if (isUnassignedOnlooker(bees, i))
	{
		//scegliere posizione
		setTrial(bees, i, 0);
		setType(bees, i, ASSIGNED_ONLOOKER);
	}
}
	
	BOOL isUnassignedOnlooker(Bees bees, int i)
	{
		return getType(bees, i) == UNASSIGNED_ONLOOKER;
	}



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
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
		setTrial(bees, i, 0);
		bees->p[i] = 0.0;
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
	if (isEmployed(bees, i)) {
		generateNewPosition(bees, i);
		evaluateFitness(bees, i);
		setTrial(bees, i, 0);
	}
}
	
	BOOL isEmployed(Bees bees, int i)
	{
		return getType(bees, i) == EMPLOYED;
	}

	void generateNewPosition(Bees bees, int i)
	{
		int y;
		for (y=0; y<D; y++)
			bees->positions[i][y] = chooseRandomValueBetweenRange();
	}

		float chooseRandomValueBetweenRange()
		{
			float random = ((float) rand()) / (float) RAND_MAX;
			float range = MAX_SEARCH_RANGE - MIN_SEARCH_RANGE;
			return MIN_SEARCH_RANGE + (random * range);
		}

	void evaluateFitness(Bees bees, int i)
	{
		float fitness = formulae(bees->positions[i]);
		setFitness(bees, i, fitness);
	}
		
			

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

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
			if (i < NUMBER_OF_EMPLOYED)
				setType(bees, i, EMPLOYED);
			else
				setType(bees, i, UNASSIGNED_ONLOOKER);
		}



void employedPlacement(Bees bees, int i)
{
	float fitness;
	if (isEmployed(bees, i)) 
	{
		generateNewPosition(bees, i);
		fitness = evaluateFitness(bees->positions[i]);
		setFitness(bees, i, fitness);
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
			bees->positions[i][y] = chooseRandomValueBetweenRange(MIN_SEARCH_RANGE, MAX_SEARCH_RANGE);
	}

		float chooseRandomValueBetweenRange(float lowerBound, float upperBound)
		{
			float random = ((float) rand()) / (float) RAND_MAX;
			float range = upperBound - lowerBound;
			return lowerBound + (random * range);
		}

	float evaluateFitness(float position[])
	{
		return formulae(position);
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



void foodExploitation(Bees bees, int i)
{
	float perturbedPosition[D];

	if (hasExceededTheLimit(bees, i))
	{
		if (isEmployed(bees, i))
			employedPlacement(bees, i);
		else
			setType(bees, i, UNASSIGNED_ONLOOKER);
	}
	else
	{
		generatePerturbedPosition(bees, i, perturbedPosition);
		chooseBestPosition(bees, i, perturbedPosition);
	}
}

	BOOL hasExceededTheLimit(Bees bees, int i)
	{
		return getTrial(bees, i) > LIMIT;
	}

	void generatePerturbedPosition(Bees bees, int i, float perturbedPosition[])
	{
		int y, k;
		for (y=0; y<D; y++)
		{
			k = chooseIndex(i);
			perturbedPosition[y] = bees->positions[i][y] + chooseRandomValueBetweenRange(-1.0, 1.0) * (bees->positions[i][y] - bees->positions[k][y]);
			controlifExceedSearchField(perturbedPosition, y);
		}
	}

		int chooseIndex(int i)
		{
			int index;
			do
				index = (rand() % (SN - 0)) + 0;
			while (index == i);

			return index;
		}

		void controlifExceedSearchField(float newPosition[], int y)
		{
			if (newPosition[y] > MAX_SEARCH_RANGE)
				newPosition[y] = MAX_SEARCH_RANGE;
			else if (newPosition[y] < MIN_SEARCH_RANGE)
				newPosition[y] = MIN_SEARCH_RANGE;
		}

	void chooseBestPosition(Bees bees, int i, float perturbedPosition[])
	{
		int trial;
		float perturbedFitness = evaluateFitness(perturbedPosition);

		if (isPerturbedFitnessBetter(bees, i, perturbedFitness))
		{
			setPosition(bees, i, perturbedPosition);
			setFitness(bees, i, perturbedFitness);
			setTrial(bees, i, 0);
		}
		else
		{
			trial = getTrial(bees, i);
			setTrial(bees, i, trial+1);
		}
	}

		BOOL isPerturbedFitnessBetter(Bees bees, int i, float perturbedFitness)
		{
			return getFitness(bees, i) > perturbedFitness;
		}

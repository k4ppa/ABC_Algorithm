#include "bees.h"

void initializeType(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
		chooseBeeType(bees, i);
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
		//setP(bees, i, 0.0);
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
		char stringFitness[28];
		mpf_t mpfFitness, one;
		float ris;
		float fitness = formulae(position);
		if (fitness >= 0) 
		{
			sprintf(stringFitness, "%.20f", fitness);
			mpf_init(mpfFitness);
			mpf_init(one);
			
			mpf_set_str (one, "1.0", 10);
			mpf_set_str(mpfFitness, stringFitness, 10);
			
			mpf_add(mpfFitness, mpfFitness, one);
			//printf("fitness: %.20e\t", fitness);
			//mpf_out_str (stdout, 10, 256, mpfFitness);
			mpf_div(mpfFitness, one, mpfFitness);			
			
			printf("\nris %.20e\t", (float) mpf_get_d(mpfFitness));
			ris = (float) mpf_get_d(mpfFitness);
			mpf_out_str (stdout, 10, 256, mpfFitness);
			printf("\n");
			return ris;
			//return 1 / (1 + fitness);
		}
		return 1 + fabs(fitness);
	}
		
			

void onlookerPlacement(Bees bees, int i)
{
	//generateEmployedP(bees, i);
	if (isUnassignedOnlooker(bees, i))
	{
		chooseOnlookerPosition(bees, i);
		setTrial(bees, i, 0);
		setType(bees, i, ASSIGNED_ONLOOKER);
	}
}

	void generateEmployedP(Bees bees, int i)
	{
		float newP;
		if (isEmployed(bees, i)) 
			newP = calcolateP(bees, i);
			setP(bees, i, newP);
	}
	
		float calcolateP(Bees bees, int i)
		{
			float fitnessSummation = 0.0;
			int y;
			for (y=0; y<NUMBER_OF_EMPLOYED; y++)
				fitnessSummation = fitnessSummation + getFitness(bees, i);
			return getFitness(bees, i) / fitnessSummation;
		}

	BOOL isUnassignedOnlooker(Bees bees, int i)
	{
		return getType(bees, i) == UNASSIGNED_ONLOOKER;
	}

	void chooseOnlookerPosition(Bees bees, int i)
	{
		int selectedEmployed = rouletteWheelEmployedSelection(bees);
		moveOnlookerInPosition(bees, i, selectedEmployed);
	}

		int rouletteWheelEmployedSelection(Bees bees)
		{
			float totalFitness = getFitness(bees, 0);
			int y;
			for (y=1; y<NUMBER_OF_EMPLOYED; y++)
			{
				totalFitness = totalFitness + getFitness(bees, y);
				if (chooseRandomValueBetweenRange(0.0f, 1.0f) < getFitness(bees, y) / totalFitness)
					return y;
			}
			return 0;
		}

		void moveOnlookerInPosition(Bees bees, int i, int selectedEmployed)
		{
			setPosition(bees, i, getPosition(bees, selectedEmployed));
			setFitness(bees, i, getFitness(bees, selectedEmployed));
		}
	


void foodExploitation(Bees bees, int i)
{
	if (hasExceededTheLimit(bees, i))
		resetBee(bees, i);
	else
		tryToFindBetterPosition(bees, i);
}

	BOOL hasExceededTheLimit(Bees bees, int i)
	{
		return getTrial(bees, i) > LIMIT;
	}


	void resetBee(Bees bees, int i)
	{
		if (isEmployed(bees, i))
			employedPlacement(bees, i);
		else
			setType(bees, i, UNASSIGNED_ONLOOKER);
	}

	void tryToFindBetterPosition(Bees bees, int i)
	{
		float perturbedPosition[D];
		generatePerturbedPosition(bees, i, perturbedPosition);
		chooseBestPosition(bees, i, perturbedPosition);
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
		float perturbedFitness = evaluateFitness(perturbedPosition);

		if (isPerturbedFitnessBetter(bees, i, perturbedFitness))
			replacePosition(bees, i, perturbedPosition, perturbedFitness);	
		else
			increaseTrial(bees, i);
	}

		BOOL isPerturbedFitnessBetter(Bees bees, int i, float perturbedFitness)
		{
			return getFitness(bees, i) < perturbedFitness;
		}

		void replacePosition(Bees bees, int i, float perturbedPosition[], float perturbedFitness)
		{
			setPosition(bees, i, perturbedPosition);
			setFitness(bees, i, perturbedFitness);
			setTrial(bees, i, 0);
		}

		void increaseTrial(Bees bees, int i)
		{
			int trial = getTrial(bees, i);
			setTrial(bees, i, trial+1);
		}

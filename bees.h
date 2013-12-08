#ifndef BEES_H_
#define BEES_H_

#include <stdlib.h>
#include "types.h"
#include "costant.h"
#include "sphere.h"

#define EMPLOYED 1
#define ASSIGNED_ONLOOKER 2
#define UNASSIGNED_ONLOOKER 3

struct bees
{
	Flag type[SN];
	float positions[SN][D];
	float fitness[SN];
	float p[SN];
	int trial[SN];
};
typedef struct bees *Bees;


void initializeBees(Bees bees);
	void setBee(Bees bees, int i);
		void chooseBeeType(Bees bees, int i);
			

void employedPlacement(Bees bees, int);
	BOOL isEmployed(Bees bees, int i);
	void generateNewPosition(Bees bees, int i);
		float chooseRandomValueBetweenRange(float lowerBound, float upperBound);
	float evaluateFitness(float position[]);


void onLookerPlacement();
	BOOL isUnassignedOnlooker(Bees bees, int i);


void foodExploitation(Bees bees, int i);
	BOOL hasExceededTheLimit(Bees bees, int i);
	void generatePerturbedPosition(Bees bees, int i, float perturbedPosition[]);
		int chooseIndex(int i);
		void controlifExceedSearchField(float newPosition[], int y);
	void chooseBestPosition(Bees bees, int i, float perturbedPosition[]);
		BOOL isPerturbedFitnessBetter(Bees bees, int i, float perturbedFitness);
		void replacePosition(Bees bees, int i, float perturbedPosition[], float perturbedFitness);
		void increaseTrial(Bees bees, int i);
	

void setType(Bees bees, int i, unsigned int newType);
unsigned int getType(Bees bees, int i);
void setTrial(Bees bees, int i, int newTrial);
int getTrial(Bees bees, int i);
void setFitness(Bees bees, int i, float newFitness);
float getFitness(Bees bees, int i);
void setPosition(Bees bees, int i, float newPosition[]);
			

#endif


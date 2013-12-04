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
typedef struct bees Bees;


void initializeBees(Bees bees);
	void setBee(Bees bees, int i);
		void chooseBeeType(Bees bees, int i);
			

void employedPlacement(Bees bees, int);
	BOOL isEmployed(Bees bees, int i);
	void generateNewPosition(float position[]);
		float chooseRandomValueBetweenRange();


void onLookerPlacement();
	BOOL isUnassignedOnlooker(Bees bees, int i);
	

void setType(Bees bees, int i, unsigned int newType);
unsigned int getType(Bees bees, int i);
void setTrial(Bees bees, int i, int newTrial);
int getTrial(Bees bees, int i);
			

#endif


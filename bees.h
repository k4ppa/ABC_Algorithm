#ifndef BEES_H_
#define BEES_H_

#include "types.h"
#include "costant.h"

#define EMPLOYED 1
#define ASSIGNED_ONLOOKER 2
#define NOT_ASSIGNED_ONLOOKER 3


struct bees
{
	float positions[SN][D];
	Flag type[SN];
	int trial[SN];
	float p[SN];
};
typedef struct bees Bees;


void initializeBees(Bees bees);
	void setBee(Bees bees, int i);
		void chooseBeeType(Bees bees, int i);
			void setType(Bees bees, int i, unsigned int newType);

void onLookerPlacement();
	Flag getType();
			

#endif


#ifndef BESTBEE_H_
#define BESTBEE_H_

#include "costant.h"
#include "types.h"

struct bestBee
{
	double bestPosition[D];
	double bestFitness;
	BOOL inizialized;
};
typedef struct bestBee *BestBee;

void setBestFitness(BestBee bestBee, double newBestFitness);
double getBestFitness(BestBee bestBee);
void setBestPosition(BestBee bestBee, double newBestPosition[]);
double *getBestPosition(BestBee bestBee);
void setInizializedTrue(BestBee bestBee);
void setInizializedFalse(BestBee bestBee);
BOOL getInizialized(BestBee bestBee);

#endif

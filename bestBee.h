#ifndef BESTBEE_H_
#define BESTBEE_H_

#include "costant.h"

struct bestBee
{
	float bestPosition[D];
	float bestFitness;
};
typedef struct bestBee *BestBee;

void setBestFitness(BestBee bestBee, float newBestFitness);
float getBestFitness(BestBee bestBee);
void setBestPosition(BestBee bestBee, float newBestPosition[]);
float *getBestPosition(BestBee bestBee);

#endif

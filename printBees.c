#include "printBees.h"

void printBestBee(BestBee bestBee)
{
	int i;

	printf("\t\t\t\t*** BESTBEE ***\n");
	printf("Fitness %f\n", getBestFitness(bestBee));
	for (i=0; i<D; i++)
		printf("%f\t", getBestPosition(bestBee));
	printf("\n");
}
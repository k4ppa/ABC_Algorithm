#include "printBees.h"

void printBestBee(BestBee bestBee)
{
	dprintf("\tB\t*\t%f\t%.2e\n", getBestFitness(bestBee), getBestFitness(bestBee));
	printPosition(getBestPosition(bestBee));
	printf("\n");
}

void printBees(Bees bees)
{
    int i;
    for (i=0; i<SN; i++)
    {
        dprintf("\t%d\t%d\t%f\n", getType(bees, i), getTrial(bees, i), getFitness(bees, i));
        printPosition(bees->positions[i]);
		printf("\n-------------------------------------------------------------------------------\n");
    }
	printf("--------------------------------------------------------------------------------\n");
}

void printPosition(float position[])
{
	int y;
	for(y=0; y<D; y++)
		dprintf("%f\t", position[y]);
	printf("\n");
}

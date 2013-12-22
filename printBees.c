#include "printBees.h"

void printBestBee(BestBee bestBee)
{
	printf("\tB\t*\t%Le\t%Le\n", getBestFitness(bestBee), (1 / getBestFitness(bestBee)) - 1);
	printPosition(getBestPosition(bestBee));
	printf("\n");
}

void printBees(Bees bees)
{
    int i;
    for (i=0; i<SN; i++)
    {
        dprintf("\t%d\t%d\t%e\n", getType(bees, i), getTrial(bees, i), getFitness(bees, i));
        //printPosition(bees->positions[i]);
		dprintf("\n-------------------------------------------------------------------------------\n");
    }
	dprintf("--------------------------------------------------------------------------------\n");
}

void printPosition(double position[])
{
	int y;
	for(y=0; y<D; y++)
		printf("%e\t", position[y]);
	printf("\n");
}

#include "printBees.h"

void printBestBee(BestBee bestBee)
{
	printf("TYPE\t\t\tFITNESS\t\t\t\tTRIAL\n");
	printf("best\t\t\t%f\t\t*\n", getBestFitness(bestBee));
	printPosition(getBestPosition(bestBee));
}


void printBees(Bees bees)
{
    int i;
	printf("TYPE\t\t\tFITNESS\t\t\t\tTRIAL\n");
    for (i=0; i<SN; i++)
    {
        printf("%d\t\t\t%f\t\t%d\n", getType(bees, i), getFitness(bees, i), getTrial(bees, i));
        printPosition(bees->positions[i]);
		printf("***\t\t\t***\t\t***\n");
    }
}

void printPosition(float position[])
{
	int y;
	for(y=0; y<D; y++)
		printf("%f\t", position[y]);
	printf("\n");
}

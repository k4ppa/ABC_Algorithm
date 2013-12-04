#include "bees.h"
#include "types.h"
#include "sphere.h"
	
void printPosition(float position[])
{
	int y;
	printf("position: ");
	for(y=0; y<D; y++)
		printf("%f\t", position[y]);
	printf("\n");
}

void printBees(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
	{
		printf("type: %d\n", bees->type[i].bits);
		printf("fitness: %f\n", bees->fitness[i]);
		printPosition(bees->positions[i]);
		printf("trial: %d\n", bees->trial[i]);
		printf("p: %f\n\n", bees->p[i]);
	}
}


int main()
{
	Bees bees = NULL;
	int i;
	bees = (Bees) malloc(sizeof (struct bees));

	initializeBees(bees);

	for(i=0; i<SN; i++)
		employedPlacement(bees, i);
	printBees(bees);

	system("PAUSE");
	return 0;
}
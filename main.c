#include "bees.h"
#include "types.h"
#include "sphere.h"
#include <time.h>
	
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
		printf("p: %f\n\n\n", bees->p[i]);
	}
}


int main()
{
	Bees bees = NULL;
	int i, k;
	float values[10];
	
	bees = (Bees) malloc(sizeof (struct bees));

	srand(time(0));
	initializeBees(bees);

	for(i=0; i<SN; i++)
		employedPlacement(bees, i);
	printBees(bees);

	for (k=0; k<10; k++) 
		values[k] = chooseRandomValueBetweenRange();
		
	for (k=0; k<10; k++)
		printf("Value %d: %f\n", k, values[k]);

	system("PAUSE");
	return 0;
}
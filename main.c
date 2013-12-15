#include "bees.h"
#include "types.h"
#include <time.h>
        
void printPosition(float position[])
{
    int y;
    printf("position: ");
    for(y=0; y<D; y++)
		printf("%f  ", position[y]);
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
        printf("trial: %d\n\n\n", bees->trial[i]);
        //printf("p: %f\n\n\n", bees->p[i]);
    }
}

void prindRandomValueBetweenRange(float min, float max)
{
	float values[10];
	int k;
	for (k=0; k<10; k++) 
        values[k] = chooseRandomValueBetweenRange(min, max);
                
    for (k=0; k<10; k++)
		printf("Value(%.0f, %.0f) %d: %f\n", min, max, k, values[k]);
}


int main()
{
    Bees bees = NULL;
    int i, y;
        
    bees = (Bees) malloc(sizeof (struct bees));
	srand(time(0));
    
    initializeBees(bees);
	printf("INIZIALIZE\n");
	printBees(bees);

    for(i=0; i<SN; i++)
         employedPlacement(bees, i);
	printf("EMPLOYED PLACEMENT\n");
    printBees(bees);

	for(i=0; i<SN; i++)
		onlookerPlacement(bees, i);
	printf("ONLOOKER PLACEMENT\n");
    printBees(bees);

	for (y=0; y<10; y++)
	{
		for (i=0; i<SN; i++)
			foodExploitation(bees, i);
		printf("FOOD EXPLOITATION %d\n", y);
		printBees(bees);
	}
/*
	prindRandomValueBetweenRange(-1, 1);
	prindRandomValueBetweenRange(0, 1);
	prindRandomValueBetweenRange(-32768, 32768);
*/
    system("PAUSE");
    return 0;
}
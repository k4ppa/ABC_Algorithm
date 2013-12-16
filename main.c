#include <time.h>
//#include <stdio.h>
#include "bees.h"
#include "types.h"

int main()
{
	Bees bees = (Bees) malloc(sizeof (struct bees));
	int i, cycles;

	srand(time(0));
	for (i=0; i<D; i++)
		initializeBees(bees);

	for (i=0; i<D; i++)
		employedPlacement(bees, i);

	for (cycles=0; cycles<MAX_CYCLES; cycles++) 
	{
		for (i=0; i<D; i++)
		{
			onlookerPlacement(bees, i);
			foodExploitation(bees, i);
		}
	}

	system("PAUSE");
	return 0;
}
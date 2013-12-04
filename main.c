#include "bees.h"
#include "types.h"
#include "sphere.h"

int main()
{
	Bees bees = NULL;
	bees = (Bees) malloc(sizeof (struct bees));

	initializeBees(bees);

	return 0;
}
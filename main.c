#include "bees.h"
#include "types.h"
#include <time.h>

void inizializeValues(float values[])
{
	int i;
	for (i=0; i<D; i++)
		values[i] = 0;
}

void printValues(float values[])
{
	int i;
	for (i=0; i<D; i++)
		printf("%f\t", values[i]);
	printf("\n");
}

int main()
{
	Bees bees = NULL;
	float values[D];
	float a;
	inizializeValues(values);
	printValues(values);
	printf("f: %f\n", formulae(values));

	system("PAUSE");
	return 0;
}
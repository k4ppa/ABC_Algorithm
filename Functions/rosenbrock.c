#include "rosenbrock.h"

#if FUNCTION == ROSENBROCK

double formulae(double values[])
{
	double result = 0.0;
	double partialResult1, partialResult2;
	int i;

	for (i=0; i<D-1; i++)
	{
		partialResult1 = values[i+1] - pow(values[i], 2);
		partialResult1 = 100.0 * pow(partialResult1, 2);
		partialResult2 = values[i] - 1.0;
		partialResult2 = pow(partialResult2, 2);
		result = result + (partialResult1 + partialResult2);
	}
	return result;
}

#endif
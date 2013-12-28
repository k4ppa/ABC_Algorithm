#include "rastrigin.h"

#if FUNCTION == RASTRIGIN

double formulae(double values[])
{
	double result = 0.0;
	double partialResult;
	int i;

	for (i=0; i<D; i++)
	{
		partialResult = 2 * M_PI * values[i];
		partialResult = 10 * cos(partialResult);
		result = result + pow(values[i], 2) - partialResult + 10;
	}
	return result;
}

#endif
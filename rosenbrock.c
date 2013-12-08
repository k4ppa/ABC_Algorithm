#include "rosenbrock.h"

#if FUNCTION == ROSENBROCK

float formulae(float values[])
{
	float result = 0.0;
	float partialResult1, partialResult2;
	int i;

	for (i=0; i<D-1; i++)
	{
		partialResult1 = values[i+1] - square(values[i]);
		partialResult1 = 100.0 * square(partialResult1);
		partialResult2 = values[i] - 1.0;
		partialResult2 = square(partialResult2);
		result = result + (partialResult1 + partialResult2);
	}
	return result;
}

	float square(float value)
	{
		return value * value;
	}

#endif
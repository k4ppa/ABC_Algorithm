#include "ackley.h"

#if FUNCTION == ACKLEY

float formulae(float values[])
{	
	return firstCalculation(values) - secondCalculation(values) + 20 + (float) M_E;
}

	float firstCalculation(float values[])
	{
		float partialResult = 0.0;
		int i;

		for (i=0; i<D; i++)
			partialResult = partialResult + ((float) pow(values[i], 2));
		partialResult = -0.2f * (float) sqrt(partialResult / D);
		partialResult = -20 * (float) exp(partialResult);
		return partialResult;
	}

	float secondCalculation(float values[])
	{
		float result = 0.0;
		int i;

		for (i=0; i<D; i++)
			result = result + ((float) cos(2 * M_PI * values[i]));
		return (float) exp(result / D);
	}

#endif
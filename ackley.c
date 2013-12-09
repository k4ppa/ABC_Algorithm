#include "ackley.h"

#if FUNCTION == ACKLEY

float formulae(float values[])
{	
	return firstCalculation(values) - secondCalculation(values);
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
		float partialResult = 0.0;
		int i;

		for (i=0; i<D; i++)
			partialResult = partialResult + ((float) cos(2 * M_PI * values[i]));
		partialResult = (float) exp(partialResult / D) + 20 + (float) M_E;
		return partialResult;
	}

#endif
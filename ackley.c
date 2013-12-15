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
			partialResult = partialResult + (powf(values[i], 2));
		partialResult = -0.2f * sqrtf(partialResult / D);
		partialResult = -20 * expf(partialResult);
		return partialResult;
	}

	float secondCalculation(float values[])
	{
		float partialResult = 0.0;
		int i;

		for (i=0; i<D; i++)
			partialResult = partialResult + (cosf(2 * M_PI * values[i]));
		partialResult = expf(partialResult / D) + 20 + (float) M_E;
		return partialResult;
	}

#endif
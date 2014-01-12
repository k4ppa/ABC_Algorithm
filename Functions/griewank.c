#include "griewank.h"
#include <stdio.h>

#if FUNCTION == GRIEWANK

float formulae(float values[])
{
	float result, partialResult;
	result = calculateSummation(values) / 4000;
	partialResult = calculateProductsOfSequences(values);
	result = add(result, partialResult);
	
	return add(result, 1.0);
}

	float calculateSummation(float values[])
	{
		float result = 0.0;
		int i;
		for (i=0; i<D; i++)
			result = result + powf(values[i], 2);
		return result;
	}

	float calculateProductsOfSequences(float values[])
	{
		float result = 1.0;
		float partialResult;
		int i;
		
		for (i=0; i<D; i++) {
			partialResult = values[i] / sqrtf((float) i+1);
			result = mul(result, cos(partialResult));
		}
		return result;
	}

#endif
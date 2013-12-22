#include "griewank.h"

#if FUNCTION == GRIEWANK

double formulae(double values[])
{
	double result;
	result = calculateSummation(values) / 4000;
	result = result - calculateProductsOfSequences(values);
	return result + 1;
}

	double calculateSummation(double values[])
	{
		double result = 0.0;
		int i;
		for (i=0; i<D; i++)
			result = result + pow(values[i], 2);
		return result;
	}

	double calculateProductsOfSequences(double values[])
	{
		double result = 1.0;
		double partialResult;
		int i;
		for (i=0; i<D; i++) {
			partialResult = values[i] / sqrt((double) i+1);
			result = result * cos(partialResult);
		}
		return result;
	}

#endif
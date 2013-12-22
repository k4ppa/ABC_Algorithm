#include "ackley.h"

#if FUNCTION == ACKLEY

double formulae(double values[])
{	
	return firstCalculation(values) - secondCalculation(values) + 20 + M_E;
}

	double firstCalculation(double values[])
	{
		double partialResult = 0.0;
		int i;

		for (i=0; i<D; i++)
			partialResult = partialResult + (pow(values[i], 2));
		partialResult = -0.2 * sqrt(partialResult / D);
		partialResult = -20 * exp(partialResult);
		return partialResult;
	}

	double secondCalculation(double values[])
	{
		double result = 0.0;
		int i;

		for (i=0; i<D; i++)
			result = result + (cos(2 * M_PI * values[i]));
		return exp(result / D);
	}

#endif
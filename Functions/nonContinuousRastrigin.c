#include "nonContinuousRastrigin.h"

#if FUNCTION == NON_CONTINUOUS_RASTRIGIN

double formulae(double values[])
{
	double result = 0.0;
	double partialResult, value;
	int i;

	for (i=0; i<D; i++)
	{
		partialResult = 2 * M_PI * values[i];
		partialResult = 10 * cos(partialResult);
		value = calculateValue(values[i]);
		result = result + pow(value, 2) - partialResult + 10;
	}
	return result;
}

	double calculateValue(double value)
	{
		if (abs(value) >= 0.5)
			return (2 * (double) round(value)) / 2;
		return value;
	}

		int round(double number)
		{
			return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
		}

#endif
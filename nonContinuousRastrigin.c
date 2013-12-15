#include "nonContinuousRastrigin.h"

#if FUNCTION == NON_CONTINUOUS_RASTRIGIN

float formulae(float values[])
{
	float result = 0.0;
	float partialResult, value;
	int i;

	for (i=0; i<D; i++)
	{
		partialResult = 2 * (float) M_PI * values[i];
		partialResult = 10 * cosf(partialResult);
		value = calculateValue(values[i]);
		result = result + powf(value, 2) - partialResult + 10;
	}
	return result;
}

	float calculateValue(float value)
	{
		if (fabs(value) >= 0.5)
			return (2 * (float) round(value)) / 2;
		return value;
	}

		int round(float number)
		{
			return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
		}

#endif
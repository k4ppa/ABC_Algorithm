#include "weierstrass.h"

#if FUNCTION == WEIERSTRASS

float formulae(float values[])
{
	
	return firstCalculation(values) - (D * secondCalculation());
}

	float firstCalculation(float values[])
	{
		float result = 0.0;
		float num;
		int i;
		for (i=0; i<D; i++)
		{
			num = values[i] + 0.5f;
			result = result + calcolateSummation(num);
		}
		return result;
	}

	float secondCalculation()
	{
		return calcolateSummation(0.5);
	}

	float calcolateSummation(float num)
	{
		float result = 0.0;
		float partialResult;
		float a = 0.5;
		float b = 3.0;
		int k;
		int kMax = 20;

		for (k=0; k<kMax; k++) {
			partialResult = 2 * (float) M_PI * powf(b, k) * num;
			result = result + (powf(a, k) * cosf(partialResult));
		}
		return result;
	}

#endif
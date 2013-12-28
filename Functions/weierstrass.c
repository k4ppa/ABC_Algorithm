#include "weierstrass.h"

#if FUNCTION == WEIERSTRASS

double formulae(double values[])
{
	
	return firstCalculation(values) - (D * secondCalculation());
}

	double firstCalculation(double values[])
	{
		double result = 0.0;
		double num;
		int i;
		for (i=0; i<D; i++)
		{
			num = values[i] + 0.5f;
			result = result + calcolateSummation(num);
		}
		return result;
	}

	double secondCalculation()
	{
		return calcolateSummation(0.5);
	}

	double calcolateSummation(double num)
	{
		double result = 0.0;
		double partialResult;
		double a = 0.5;
		double b = 3.0;
		int k;
		int kMax = 20;

		for (k=0; k<kMax; k++) {
			partialResult = 2 * M_PI * pow(b, k) * num;
			result = result + (pow(a, k) * cos(partialResult));
		}
		return result;
	}

#endif
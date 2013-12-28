#include "schwefel.h"

#if FUNCTION == SCHWEFEL

double formulae(double values[])
{
	return 418.9829f * D - calculation(values);
}

	double calculation(double values[])
	{
		double result = 0.0;
		int i;

		for (i=0; i<D; i++)
			result = result + values[i] * sin(sqrt(abs(values[i])));
		return result;
	}

#endif
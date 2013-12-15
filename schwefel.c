#include "schwefel.h"

#if FUNCTION == SCHWEFEL

float formulae(float values[])
{

	return (418.9829 * D) - calculation(values);
}

	float calculation(float values[])
	{
		float result = 0.0;
		int i;

		for (i=0; i<D; i++)
			result = result + (-values[i] * sin(sqrt(abs(values[i]))));
		return result;
	}

#endif
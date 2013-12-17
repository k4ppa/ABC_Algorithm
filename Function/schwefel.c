#include "schwefel.h"

#if FUNCTION == SCHWEFEL

float formulae(float values[])
{
	return 418.9829f * D - calculation(values);
}

	float calculation(float values[])
	{
		float result = 0.0;
		int i;

		for (i=0; i<D; i++)
			result = result + values[i] * sinf(sqrtf(fabs(values[i])));
		return result;
	}

#endif
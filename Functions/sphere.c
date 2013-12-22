#include "sphere.h"

#if FUNCTION == SPHERE

double formulae(double values[])
{
	double result = 0.0;
	int i;

	for (i=0; i<D; i++)
		result = result + (values[i]*values[i]);
	return result;
}

#endif
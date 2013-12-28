#ifndef SCHWEFEL_H_
#define SCHWEFEL_H_

#include <math.h>
#include "../costant.h"

#if FUNCTION == SCHWEFEL

	#define MIN_SEARCH_RANGE -500.0
	#define MAX_SEARCH_RANGE 500.0

	double formulae(double values[]);
		double calculation(double values[]);

#endif
#endif
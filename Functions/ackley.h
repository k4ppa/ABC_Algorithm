#ifndef ACKLEY_H_
#define ACKLEY_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "../costant.h"

#if FUNCTION == ACKLEY

	#define MIN_SEARCH_RANGE -32768.0
	#define MAX_SEARCH_RANGE 32768.0

	double formulae(double values[]);
		double firstCalculation(double values[]);
		double secondCalculation(double values[]);

#endif
#endif
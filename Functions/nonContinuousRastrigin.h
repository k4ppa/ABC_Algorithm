#ifndef NON_CONTINUOUS_RASTRIGIN_H_
#define NON_CONTINUOUS_RASTRIGIN_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "../costant.h"

#if FUNCTION == NON_CONTINUOUS_RASTRIGIN

	#define MIN_SEARCH_RANGE -5.12
	#define MAX_SEARCH_RANGE 5.12

	double formulae(double values[]);
		double calculateValue(double value);
			int round(double number);

#endif
#endif
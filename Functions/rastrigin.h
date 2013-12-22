#ifndef RASTRIGIN_H_
#define RASTRIGIN_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "../costant.h"

#if FUNCTION == RASTRIGIN

	#define MIN_SEARCH_RANGE -5.12
	#define MAX_SEARCH_RANGE 5.12

	double formulae(double values[]);

#endif
#endif
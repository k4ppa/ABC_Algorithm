#ifndef ROSENBROCK_H_
#define ROSENBROCK_H_

#include "costant.h"

#if FUNCTION == ROSENBROCK

	#define MIN_SEARCH_RANGE -2048.0
	#define MAX_SEARCH_RANGE 2048.0

	float formulae(float values[]);
		float square(float value);

#endif
#endif
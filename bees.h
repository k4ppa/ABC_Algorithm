#ifndef BEES_H_
#define BEES_H_

#include "StdAfx.h"

typedef struct bees Bees;

struct bees
{
	float *positions[SN];
	twoBit type[SN];
	int trial[SN];
	float p[SN];
}

#endif


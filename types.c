#include "types.h"

void setBits(Flag type, unsigned int newType)
{
	type.bits = newType;
}

unsigned int getType(Flag type)
{
	return type.bits;
}
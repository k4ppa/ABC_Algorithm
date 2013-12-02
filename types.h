#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

struct twoBit
{
     unsigned int bits: 2;
};
typedef struct twoBit Flag;

void setBits(Flag type, unsigned int newBits);
unsigned int getBits();

#endif
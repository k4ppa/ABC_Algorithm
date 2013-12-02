#ifndef TYPES_H_
#define TYPES_H_

#include <stdio.h>

#ifndef NULL
#define NULL 0
#endif


struct twoBit
{
     unsigned int bits: 2;
};
typedef struct twoBit Flag;

void setBits(Flag type, unsigned int newType);
unsigned int getType();

#endif
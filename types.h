#ifndef TYPES_H_
#define TYPES_H_

#include "bees.h"

#ifndef NULL
#define NULL 0
#endif


struct twoBit
{
     unsigned int flag: 2;
};
typedef struct twoBit Flag;

#endif
#ifndef TYPES_H_
#define TYPES_H_

#ifndef NULL
#define NULL 0
#endif

typedef struct twobit Flag;

struct twoBit
{
     unsigned int flag: 2;
};

#endif
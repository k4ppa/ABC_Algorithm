#ifndef TYPES_H_
#define TYPES_H_

#define BOOL int
#define TRUE 1
#define FALSE 0

struct twoBit
{
     unsigned int bits: 2;
};
typedef struct twoBit Flag;

void setBits(Flag *type, unsigned int newBits);
unsigned int getBits(Flag *type);

#endif
#include "bees.h"
#include "types.h"
#include "sphere.h"

void funzione(int prova[])
{
	prova[1] = 9;
}
int main()
{
	Flag var[3];
	Bees bees;
	//int prova[3] = {0, 1, 2};
	//funzione(prova);
	//printf("%d%d%d\n", prova[0], prova[1], prova[2]);

	setBits(&var[1], 1);
	printf("bits %d\n", getBits(&var[1]));

	system("PAUSE");
	return 0;
}
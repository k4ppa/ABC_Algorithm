#include "bestBee.h"
#include "bees.h"

void beesSearch(Bees bees);
void saveBestPosition(BestBee bestBee, Bees bees);
	BOOL isBeePositionBetter(BestBee bestBee, Bees bees, int i);
	void replaceBestPosition(BestBee bestBee, Bees bees, int i);

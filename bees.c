#include "bees.h"

void initializeBees(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
		setBee(bees, i);
}

	void setBee(Bees bees, int i)
	{
		setBeeType(bees.type[i], i);
		bees.trial[i] = 0;
		bees.p[i] = 0.0;
	}

		void setBeeType(Flag type, int i)
		{
			if (i <= NUMBER_OF_EMPLOYED)
				setBits(type, EMPLOYED);
			else
				setBits(type, NOT_ASSIGNED_ONLOOKER);
		}

			
#include "bees.h"

void initializeBees(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
		setBee(bees, i);
}

	void setBee(Bees bees, int i)
	{
		chooseBeeType(bees, i);
		bees.trial[i] = 0;
		bees.p[i] = 0.0;
	}

		void chooseBeeType(Bees bees, int i)
		{
			if (i <= NUMBER_OF_EMPLOYED)
				setType(bees, i, EMPLOYED);
			else
				setType(bees, i, NOT_ASSIGNED_ONLOOKER);
		}

			void setType(Bees bees, int i, unsigned int newType)
			{
				setBits(bees.type[i], newType);
			}
/*
void onLookerPlacement(Bees bees, int i)
{
	if (getType(bees.type[i]) == NOT_ASSIGNED_ONLOOKER)
}
	
	Flag getType(Flag type)
	{
		return getBits();
	}*/
#include "bees.h"

void initializeBees(Bees bees)
{
	int i;
	for (i=0; i<SN; i++)
		setBee(bees, i);
}

	void setBee(Bees bees, int i)
	{
		chooseBeeType(bees.type[i], i);
		bees.trial[i] = 0;
		bees.p[i] = 0.0;
	}

		void chooseBeeType(Flag type, int i)
		{
			if (i <= NUMBER_OF_EMPLOYED)
				setType(type, EMPLOYED);
			else
				setType(type, NOT_ASSIGNED_ONLOOKER);
		}

			void setType(Flag type, unsigned int newType)
			{
				setBits(type, newType);
			}
/*
void onLookerPlacement(Bees bees, int i)
{
	if (getBeeType(bees.type[i]) == NOT_ASSIGNED_ONLOOKER)
}
	
	Flag getBeeType(Flag type)
	{
		return getBits();
	}*/
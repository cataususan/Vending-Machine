#include "CarouselOfCakes.h"
#include <iostream>
CarouselOfCakes::CarouselOfCakes()
{
	maxCapacity = 10;
	lowLimit = 3;
}

bool CarouselOfCakes::addCake(Cake cake)
{   if (storage.size() < maxCapacity) //conditie de adaugare prajitura
	{
		storage.push_back(cake);
		return 1;
	}
	else 
		return 0;
}

Cake CarouselOfCakes::getCake(string name)
{   if (storage.size() <= lowLimit)
	{
		     cout << "Nu sunt destule prajituri in carusel" << endl;
		     return Cake("");
	}
	else
	{
		Cake cakeReturned("");
		vector <Cake>::iterator i;
		i = storage.begin();
		while (i != storage.end())
		{
			if (i->getName() == name)
			{
				cakeReturned = *i;
				i = storage.erase(i);
				return cakeReturned;
			}
			else
			{
				i++;
			}
		}
		cout << "Prajitura nu se afla in Carusel" << endl;
		return Cake("");
	}
}

int CarouselOfCakes::getCurrentCapacity()
{
	return storage.size();
}
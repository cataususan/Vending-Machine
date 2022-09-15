#include "CommandTaker.h"
#include "CarouselOfCakes.h"
#include <iostream>
#include <Windows.h>
CommandTaker::CommandTaker()
{
	carouselRecipe.push_back(RecipeCake("Papanasi", 5));
	carouselRecipe.push_back(RecipeCake("Cu mere", 5));
	carouselRecipe.push_back(RecipeCake("Dobos", 5));

	int i;

	for (i = 0; i < 3; i++)
	{
		carousel.addCake(Cake("Papanasi"));
	}
	
	for (i = 0; i < 3; i++)
	{
		carousel.addCake(Cake("Cu mere"));
	}

	for (i = 0; i < 3; i++)
	{
		carousel.addCake(Cake("Dobos"));
		
	}
	//adaugam torturile in carusel
}

vector <Cake> CommandTaker::takeCommand(RecipeCake recipe, int nrOfCakes)
{
	if (!checkCarouselOfCakes())
	{
		refillCarousel();
	}
	Cake carouselCake("");
	
	
	vector <Cake> TortComandat;
	vector <Cake>::iterator i;
	
	int k = 0,j=0;
	//trebuie parcurs caruselul pentru a se verifica daca sunt destule prajituri, altfel se vor face
	i = carousel.storage.end();
	i = carousel.storage.begin();
	while (i != carousel.storage.end())
	{
		if (i->getName() == recipe.getName())
			k++;
		i++;
	}
	if (k >= nrOfCakes)
	{
		for (j = 0; j < nrOfCakes; j++)
		{
			carouselCake = carousel.getCake(recipe.getName());
			TortComandat.push_back(recipe.getName());
		}
			
		return TortComandat;
	}
	else
		TortComandat.push_back(cakeMaker.takeCommand(recipe,nrOfCakes));
	

	return TortComandat;
}

bool CommandTaker::checkCarouselOfCakes()
{
	if (carousel.getCurrentCapacity() > carousel.lowLimit
		&& carousel.getCurrentCapacity() <= carousel.maxCapacity)
	{
		return 1;
	}
	return 0;
}

bool CommandTaker::refillCarousel()
{
	if (checkCarouselOfCakes())
	{
		cout << "Caruselul nu are nevoie de prajituri" << endl;
		return 0;
	}
	else
	{
		cout << "Caruselul se umple" << endl;
		int j;
		vector <Cake>::iterator i;
		int Papanasi = 3, CuMere = 3, Dobos = 3,
			c1 = 0, c2 = 0, c3 = 0,t;

		for (i = carousel.storage.begin(); i != carousel.storage.end(); i++)
		{	if (i->getName() == carouselRecipe.at(0).getName())
				c1++;
			if (i->getName() == carouselRecipe.at(1).getName())
				c2++;
			if (i->getName() == carouselRecipe.at(2).getName())
				c3++;
		}
		
		
		cout << "Se reumple cu Papanasi asteptati  "<<(Papanasi-c1)*5  <<"  secunde"<<endl;
		t = Papanasi-c1;
		Sleep(5000*t);
		for (j = c1; j < Papanasi; j++)
			carousel.addCake(Cake(carouselRecipe.at(0).getName()));
		
		
		
		cout << "Se reumple cu Cu mere  " << (CuMere - c2) * 5 << "  secunde"<<endl;
		t = CuMere-c2;
		Sleep(5000 * t);
		for (j = c2; j < CuMere; j++)
			carousel.addCake(Cake(carouselRecipe.at(1).getName()));
		
		
		
		cout << "Se reumple cu Dobos  " << (Dobos - c3) * 5 << "  secunde"<<endl;
		t = Dobos -c3;
		Sleep(5000 * t);
		for (j = c3; j < Dobos; j++)
		    carousel.addCake(Cake(carouselRecipe.at(2).getName()));
		

		cout << "Caruselul a fost umplut" << endl << endl;
		return 1;
	}
}


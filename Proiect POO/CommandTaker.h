#pragma once
#include<string>
#include "RecipeCake.h"
#include "CakeMaker.h"
#include "CarouselOfCakes.h"
using namespace std;

class CommandTaker {
	vector <RecipeCake> carouselRecipe;
	CakeMaker cakeMaker;
	CarouselOfCakes carousel;
	bool checkCarouselOfCakes();
	bool refillCarousel();
	friend class CommandPanel;
	

public:
	CommandTaker();
	Cake takeCommand(RecipeCake recipe);
	vector <Cake> takeCommand(RecipeCake recipe, int nrOfCakes);
	Cake takeCommand(string nameOfCake);
	vector <Cake> getCakesFromCarousel();
    
	


};
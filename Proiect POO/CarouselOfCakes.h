#pragma once
#include <string>
#include <vector>
#include <iterator>
#include "Cake.h"

using namespace std;

class CarouselOfCakes {
	vector <Cake> storage;
	unsigned int maxCapacity = 10;
	unsigned int lowLimit = 3;
public:
	CarouselOfCakes();
	bool addCake(Cake cake);
	Cake getCake(string name);
	int getCurrentCapacity();

	friend class CommandTaker;
	friend class CommandPanel;
};
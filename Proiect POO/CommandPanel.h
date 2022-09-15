#pragma once
#include <string>
#include "CommandTaker.h"
#include<list>
using namespace std;

class CommandPanel {
	list <RecipeCake> menu;
	CommandTaker commandTaker;
public:
	CommandPanel();
	void showProducts();
	void selectProduct(string name);
	void selectProduct(string name, int numberOfProducts);
	void showProductsInCarousel();


};
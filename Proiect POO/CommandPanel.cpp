#include "CommandPanel.h"
#include <iostream>
CommandPanel::CommandPanel()
{
	menu.push_back(RecipeCake("Papanasi", 5));
	menu.push_back(RecipeCake("Cu mere", 5));
	menu.push_back(RecipeCake("Dobos", 5));
	//introducere torturi in meniu 
}

void CommandPanel::showProducts()
{   int nrpraj = 0;
	list <RecipeCake>::iterator i;
	for (i = menu.begin(); i != menu.end(); i++) //parcurgem meniul
	{
		nrpraj++;
		cout << nrpraj << ". " << i->getName() << " , secunde: "
			<< i->getTime() << endl; //afisam tortul si durata prepararii
	}
}

void CommandPanel::showProductsInCarousel()
{   vector <Cake>::iterator i;

	for (i = commandTaker.carousel.storage.begin();
		i != commandTaker.carousel.storage.end(); i++)//parcurgem depozitul
	{
		cout << i->getName() << endl;//afisam fiecare tort din depozit
	}
}

void CommandPanel::selectProduct(string name, int nrOfProducts)
{
	RecipeCake recipe("", 0);
	list <RecipeCake>::iterator i;
	vector <Cake> Tort;
	vector <Cake>::iterator j;

	for (i = menu.begin(); i != menu.end(); i++) //parcurgem meniul
	{
		if (i->getName() == name) //cautam numele in meniu
		{
			recipe = *i;
			break;
		}
	}

	Tort = commandTaker.takeCommand(recipe, nrOfProducts);

	cout << "Ati primit " << nrOfProducts << " x " << name << endl << endl;
	cout << "  $$  $$  $$"<<"\n";
	cout << "__||__||__||__" << "\n";
	cout << "| ** * * * * *|" << "\n";
	cout << "|** * * * * * |" << "\n";
	cout << "| ** * * * * *|" << "\n";
	cout<<	"|_____________| "<<"\n";
}
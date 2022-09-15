#include "CakeMaker.h"
#include <Windows.h>
#include <iostream>
CakeMaker::CakeMaker()
{

}

Cake CakeMaker::takeCommand(RecipeCake recipe,int nr)
{
	cout << "Prajiturile vor fi gata in " << recipe.getTime()*nr << " secunde"<<endl;
	Sleep(recipe.getTime() * 1000*nr);
	return Cake(recipe.getName());
	
}
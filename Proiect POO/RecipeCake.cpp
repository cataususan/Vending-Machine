#include "RecipeCake.h"
#include <iostream>

RecipeCake::RecipeCake(string name, int time)
{
	this->name = name;
	this->time = time;
}

string RecipeCake::getName()
{
	return name;
}

int RecipeCake::getTime()
{
	return time;
}
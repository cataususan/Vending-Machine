#pragma once
#include <string>
#include "Cake.h"
#include "RecipeCake.h"
using namespace std;

class CakeMaker {
public:
	CakeMaker();
	Cake takeCommand(RecipeCake recipe,int nr);


};

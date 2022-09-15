#pragma once
#include <string>
using namespace std;
class RecipeCake {
	string name;
	int time;
public:
	RecipeCake(string name, int time);
	string getName();
	int getTime();
};

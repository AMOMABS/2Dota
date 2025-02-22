#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "AbstractHero.h"

class HeroView
{
public:
	void displayHeroes(const std::vector<AbstractHero*>& heroes);
	void hello();
	void menu();
	void exitGame();
};




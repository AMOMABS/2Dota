#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "AbstractHero.h"
#include "Personagem.h"

class HeroView
{
public:
	void displayHeroes(const std::vector<AbstractHero*>& heroes);
	void hello();
	void menu();
	void exitGame();
	void firstStep();
	void start();
	void choose();
	void gameMenu();
	void profile(Person::personData ps);
};




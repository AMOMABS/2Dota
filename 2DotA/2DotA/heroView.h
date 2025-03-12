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
	void displayThings(const std::vector<AbstractThings*>& things);
	void hello();
	void menu();
	void exitGame();
	void firstStep();
	void start();
	void choose();
	void gameMenu();
	void profile(Person::personData ps);
	void shopMenu();
	void thingInfo(AbstractThings::thingData thing);
	void displayPlayers(const std::vector<Person*>& players);
	
};




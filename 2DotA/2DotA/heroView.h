#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "AbstractHero.h"
#include "Personagem.h"
#include "Tower.h"
#include "Locations.h"

class HeroView
{
public:
	void displayHeroes(const std::vector<AbstractHero*>& heroes);
	void displayThings(const std::vector<AbstractThings*>& things);
	void displayInv(AbstractHero* hero);
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
	void print(int x);
	void fightPrint(int x, Person* pers,Tower tower);
	void fightPersPrint(int x, Person* pers, std::map <std::string, std::vector <Person*>> players);
	void printMap(const std::vector<Person*>& players, const Person& pers);
	void printGo(const std::vector <point>& go);
	void printFightTower(const Person& pers, const Tower& tower);
	
};




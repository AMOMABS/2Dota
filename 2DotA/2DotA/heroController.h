#pragma once
#include "Point.h"
#include "heroModel.h"
#include "heroView.h"
#include <chrono>
#include <conio.h>

class HeroController
{
private:
	HeroModel model;
	HeroView view;
public:
	void addHero(AbstractHero* heroname);

	void showHeroes();

	void startgame();

	int input();

	void choice(int x);

	void persName(const std::string& name);

	void game();

	void cases(int x);

	void go(int x);

	bool isDie();

	void isDieOutro();

	void fightWithTower(Person&, Tower&, int x);

	Tower* checkNearTowers(std::vector <Tower*> towers);
	std::map <std::string,std::vector <Person*>> checkNearPerson();

	void fight(int x);

	void lvlCheck();

	bool youWin();
};

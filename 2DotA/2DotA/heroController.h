#pragma once
#include "heroModel.h"
#include "heroView.h"

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

};

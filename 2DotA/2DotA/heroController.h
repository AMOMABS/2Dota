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
};

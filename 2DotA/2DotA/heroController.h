#pragma once
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

	void addAtributes(Person& pers, AbstractThings* thing);

	void cases(int x);
};

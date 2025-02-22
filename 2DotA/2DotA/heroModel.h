#pragma once
#include <vector>
#include <string>
#include "AbstractHero.h"

class HeroModel
{
private:
	std::vector<AbstractHero*> heroes;
public:
	void addHero(AbstractHero* hero);

	std::vector<AbstractHero*> getHeroes() const;
};


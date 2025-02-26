#pragma once
#include <vector>
#include <string>
#include "AbstractHero.h"
#include "Personagem.h"

class HeroModel
{
private:
	Person pers;
	std::vector<AbstractHero*> heroes;
public:
	HeroModel();
	void addHero(AbstractHero* hero);
	Person& get_person();
	std::vector<AbstractHero*> getHeroes() const;
};


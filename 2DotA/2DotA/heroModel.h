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
	std::vector<AbstractThings*> shopList;
	std::vector<Person*> players;
	std::vector<AbstractHero*> newHeroes;
	std::vector<std::string> names;

	void deleteHero(AbstractHero* hero);

public:
	HeroModel();
	void addHero(AbstractHero* hero);
	void addThing(AbstractThings* hero);
	void addPlayer(Person* player);
	void createRandPlayer();
	void createNewHeroes();

	
	Person& get_person();
	std::vector<AbstractHero*> getHeroes() const;
	std::vector<AbstractThings*> getThings() const;
	std::vector<Person*> getPlayers() const;

};


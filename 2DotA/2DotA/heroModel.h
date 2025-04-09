#pragma once
#include <vector>
#include <string>
#include "AbstractHero.h"
#include "Personagem.h"
#include <map>

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
	void addThing(AbstractThings* thing);
	void addPlayer(Person* player);
	void createRandPlayer();
	void createNewHeroes();
	void addHeroThing(AbstractThings* thing);
	void setGoldForPlayers(int x);
	void randomBuy();
	void addAtributes(Person& pers, AbstractThings* thing);
	std::vector<point> possibility(const point& point);

	
	Person& get_person();
	std::vector<AbstractHero*> getHeroes() const;
	std::vector<AbstractThings*> getThings() const;
	std::vector<Person*> getPlayers() const;

};


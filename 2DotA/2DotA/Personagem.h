#pragma once
#include "AbstractHero.h"

class Person {
private:
	std::string name;
	AbstractHero* hero;
	int gold;
	int goldPlus;
public:
	Person(std::string name, AbstractHero* hero, int gold = 0, int goldPlus = 500) : name(name), hero(hero), gold(gold), goldPlus(goldPlus){}

	struct personData {
		std::string name;
		AbstractHero* hero;
		int gold;
		int goldPlus;
		
		
	};
	personData get_info() {
		return personData{ name,hero,gold,goldPlus };
	}
	void setName(const std::string& newName) {
		name = newName;
	}
	void setPersHero(AbstractHero* newHero) {
		hero = newHero;
	}
};

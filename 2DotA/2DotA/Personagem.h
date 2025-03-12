#pragma once
#include "AbstractHero.h"

class Person {
private:
	std::string name;
	AbstractHero* hero;
	std::string team;
	int gold;
	int goldPlus;
	
public:
	Person(std::string name, AbstractHero* hero, std::string team,int gold, int goldPlus);

	struct personData {
		std::string name;
		AbstractHero* hero;
		int gold;
		int goldPlus;
		std::string team;
	};
	personData get_info();
	std::string getName();
	void setName(const std::string& newName);
	void setPersHero(AbstractHero* newHero);
	AbstractHero* getPersHero();
	std::string getTeam();
	void setTeam(std::string newTeam);
};

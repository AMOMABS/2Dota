#pragma once
#include "AbstractHero.h"
#include "Point.h"
#include "Locations.h"

class Person {
private:
	std::string name;
	AbstractHero* hero;
	std::string team;
	int gold;
	int goldPlus;
	point persPoint;
	int lvl;
	int xp;
	int preXp;
	
public:
	Person(std::string name, AbstractHero* hero, std::string team,int gold, int goldPlus, point persPoint,int lvl, int xp);

	struct personData {
		std::string name;
		AbstractHero* hero;
		int gold;
		int goldPlus;
		std::string team;
		point persPoint;
		int lvl;
		int xp;
		int preXp;
	};
	personData get_info() const;
	std::string getName() const;
	void setName(const std::string& newName);
	void setPersHero(AbstractHero* newHero);
	AbstractHero* getPersHero() const;
	std::string getTeam() const;
	void setTeam(std::string newTeam);
	void setGold(int x);
	void setPersPoint(int x,int y);
	point getPersPoint() const;
	void setXp(int x);
	void xpInLvl();
};

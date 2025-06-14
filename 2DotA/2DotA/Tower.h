#pragma once
#include "Point.h"
#include <string>

class Tower
{
private:
	std::string name;
	int hp;
	int damage;
	point Point;
	std::string team;
public:
	Tower(std::string,std::string,int,int,point);

	int getHp() const;
	int getDamage() const;
	void setHp(int newHp);
	point getPoint() const;
	std::string getTeam();
	
};


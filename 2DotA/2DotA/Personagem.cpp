#include "Personagem.h"


Person::Person(std::string name, AbstractHero* hero, std::string team, int gold, int goldPlus,point persPoint,int lvl,int xp) : name(name), hero(hero), team(team), gold(gold), goldPlus(goldPlus),persPoint(persPoint),lvl(lvl),xp(xp),preXp(100) {}

Person::personData Person::get_info() const{
	return personData{ name,hero,gold,goldPlus,team, persPoint,lvl,xp,preXp};
}

void Person::setName(const std::string& newName) {
	name = newName;
}
void Person::setPersHero(AbstractHero* newHero) {
	hero = newHero;
}
AbstractHero* Person::getPersHero() const{
	return hero;
}

std::string Person::getTeam() const{
	return team;
}

void Person::setTeam(std::string newTeam) {
	team = newTeam;
}
std::string Person::getName() const{
	return name;
}

void Person::setGold(int x) {
	gold += x;
}

void Person::setPersPoint(int x, int y) {
	persPoint = point{ x,y };
	if (team == "moon") {
		if (persPoint == Moon_fontain) {
			hero->setHp(hero->getMaxHp());
		}
	}
	else {
		if (persPoint == Sun_fontain) {
			hero->setHp(hero->getMaxHp());
		}
	}
	
}

point Person::getPersPoint() const{
	return persPoint;
}
void Person::setXp(int x) {
	xp += x;
}
void Person::xpInLvl() {
	if (preXp <= xp) {
		lvl++;
		xp -= preXp;
		preXp += 100;
		getPersHero()->setAtributes(150, 70, 150, 70, 3, 3, 3, 0, 7, 15);
	}
	
}

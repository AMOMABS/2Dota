#include "Personagem.h"


Person::Person(std::string name, AbstractHero* hero, std::string team, int gold, int goldPlus) : name(name), hero(hero), team(team), gold(gold), goldPlus(goldPlus) {}

Person::personData Person::get_info() const{
	return personData{ name,hero,gold,goldPlus,team };
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

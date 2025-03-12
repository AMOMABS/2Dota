#include "Personagem.h"


Person::Person(std::string name, AbstractHero* hero, std::string team, int gold, int goldPlus) : name(name), hero(hero), team(team), gold(gold), goldPlus(goldPlus) {}

Person::personData Person::get_info() {
	return personData{ name,hero,gold,goldPlus,team };
}

void Person::setName(const std::string& newName) {
	name = newName;
}
void Person::setPersHero(AbstractHero* newHero) {
	hero = newHero;
}
AbstractHero* Person::getPersHero() {
	return hero;
}

std::string Person::getTeam() {
	return team;
}

void Person::setTeam(std::string newTeam) {
	team = newTeam;
}
std::string Person::getName() {
	return name;
}

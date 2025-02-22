#include "heroModel.h"


void HeroModel::addHero(AbstractHero* hero) {
	heroes.push_back(hero);
}

std::vector<AbstractHero*> HeroModel::getHeroes() const {
	return heroes;
}

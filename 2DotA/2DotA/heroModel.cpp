#include "heroModel.h"
#include "Magnus.h"
#include "Invoker.h"
#include "PhantomAssasin.h"
#include "Pudge.h"
#include "ShadowFiend.h"
#include "AntiMage.h"

HeroModel::HeroModel() {
	addHero(new Magnus());
	addHero(new Invoker());
	addHero(new PhantomAssasin());
	addHero(new ShadowFiend());
	addHero(new AntiMage());
	addHero(new Pudge());

}
void HeroModel::addHero(AbstractHero* hero) {
	heroes.push_back(hero);
}

std::vector<AbstractHero*> HeroModel::getHeroes() const {
	return heroes;
}

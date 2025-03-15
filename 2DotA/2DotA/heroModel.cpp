#include "heroModel.h"
#include "Magnus.h"
#include "Invoker.h"
#include "PhantomAssasin.h"
#include "Pudge.h"
#include "ShadowFiend.h"
#include "AntiMage.h"
#include "ArcaneBoots.h"

std::vector <std::string> teams{ "moon","sun" };
int moonCount = 0;

HeroModel::HeroModel() :pers("", nullptr, "", 500, 500) , names({ "Jonny", "Stacy", "Monesy", "Morgen", "Bob", "Rafael","Pivozavr"}) {
	addHero(new Magnus());
	addHero(new Invoker());
	addHero(new PhantomAssasin());
	addHero(new ShadowFiend());
	addHero(new AntiMage());
	addHero(new Pudge());
	addThing(new Boots());
	addThing(new ArcaneBoots());
}
void HeroModel::addHero(AbstractHero* hero) {
	heroes.push_back(hero);
}
void HeroModel::addThing(AbstractThings* thing) {
	shopList.push_back(thing);
}

void HeroModel::addPlayer(Person* player) {
	players.push_back(player);
}
Person& HeroModel::get_person(){
	return pers;
}

std::vector<AbstractHero*> HeroModel::getHeroes() const {
	return heroes;
}

std::vector<AbstractThings*> HeroModel::getThings() const {
	return shopList;
}

std::vector<Person*> HeroModel::getPlayers() const {
	return players;
}

void HeroModel::createRandPlayer() {
	int y;
	int x;
	do {
		y = rand() % newHeroes.size();
		x = rand() % names.size();
		if (moonCount < heroes.size() / 2) {
			players.push_back(new Person{ names[x],newHeroes[y],teams[0],0,500});
			moonCount++;
		}
		else {
			players.push_back(new Person{ names[x],newHeroes[y],teams[1],0,500});
		}
		deleteHero(newHeroes[y]);
	} while (newHeroes.size()>0);
}

void HeroModel::deleteHero(AbstractHero* hero) {
	newHeroes.erase(find(newHeroes.begin(), newHeroes.end(), hero));
}

void HeroModel::createNewHeroes() {
	newHeroes.resize(heroes.size());
	for (int i = 0; i < heroes.size(); i++){
		newHeroes[i] = heroes[i];
	}
	deleteHero(pers.getPersHero());
	int temp = rand() % 2;
	pers.setTeam(teams[temp]);
	if (temp == 0) {
		moonCount++;
	}
	createRandPlayer();
}

void HeroModel::addHeroThing(AbstractThings* thing) {
	pers.getPersHero()->get_inv().push_back(thing);
}


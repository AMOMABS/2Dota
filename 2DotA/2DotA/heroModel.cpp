#include "heroModel.h"
#include "Magnus.h"
#include "Invoker.h"
#include "PhantomAssasin.h"
#include "Pudge.h"
#include "ShadowFiend.h"
#include "AntiMage.h"
#include "ArcaneBoots.h"
#include "Radiance.h"

std::vector <std::string> teams{ "moon","sun" };
int moonCount = 0;
int sunCount = 0;

HeroModel::HeroModel() :pers("", nullptr, "", 500, 500,{-1,-1}), names({"Jonny", "Stacy", "Monesy", "Morgen", "Bob", "Rafael","Pivozavr"}) {
	addHero(new Magnus());
	addHero(new Invoker());
	addHero(new PhantomAssasin());
	addHero(new ShadowFiend());
	addHero(new AntiMage());
	addHero(new Pudge());
	addThing(new Boots());
	addThing(new ArcaneBoots());
	addThing(new Radiance());
	
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
			players.push_back(new Person{ names[x],newHeroes[y],teams[0],0,500,{198,4+moonCount} });
			moonCount++;
		}
		else {
			players.push_back(new Person{ names[x],newHeroes[y],teams[1],0,500,{4,75-sunCount} });
			sunCount++;
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
		pers.setPersPoint(198,4);
	}
	else {
		sunCount++;
		pers.setPersPoint(4, 75);
	}
	createRandPlayer();
}

void HeroModel::addHeroThing(AbstractThings* thing) {
	pers.getPersHero()->get_inv().push_back(thing);
}

void HeroModel::setGoldForPlayers(int x) {
	get_person().setGold(get_person().get_info().goldPlus * (x));
	for (int i = 0; i < players.size(); i++) {
		players[i]->setGold(players[i]->get_info().goldPlus * (x));
	}
}

void HeroModel::randomBuy() {
	for (int i = 0; i < players.size(); i++) {
		int temp = rand() % 2;
		std::vector <AbstractThings*> possibleBuy;
		if (temp == 0) {
			int gold = players[i]->get_info().gold;
			for (int i = 0; i < shopList.size(); i++) {
				if (shopList[i]->getInfo().cost <= gold) {
					possibleBuy.push_back(shopList[i]);
				}
			}
			if (possibleBuy.size() != 0) {
				temp = rand() % possibleBuy.size();
				players[i]->getPersHero()->get_inv().push_back(possibleBuy[temp]);
				players[i]->setGold(-(possibleBuy[temp]->getInfo().cost));
				addAtributes(*players[i], possibleBuy[temp]);
			}
		}
		else {
			continue;
		}
	}
}

void HeroModel::addAtributes(Person& pers, AbstractThings* thing) {
	pers.getPersHero()->setAtributes(thing->getInfo().hp, thing->getInfo().mana, thing->getInfo().plusForce, thing->getInfo().plusAgility, thing->getInfo().plusIntelligence, thing->getInfo().plusAttackSpeed, thing->getInfo().plusAttackDamage, thing->getInfo().plusMoveSpeed);
}

std::vector<point> HeroModel::possibility(const point& Point) {
	if (Point == point{ 22,74 }) {
		std::vector <point> go{ {65,73}, { 4,75 },{81, 65} };
		return go;
	}
	else if (Point == point{ 4,75 }) {
		std::vector <point> go{ {40,57},{22,74},{20,55}};
		return  go;
	}
	else if (Point == point{ 40,57 }) {
		std::vector <point> go{ {80,45} ,{4,75} };
		return go;
	}
	else if (Point == point{ 80,45 }) {
		std::vector <point> go{ {40,57},{60,34},{81,65} };
		return go;
	}
	else if (Point == point{81, 65}) {
		std::vector <point> go{{ 80,45 },{22,74} };
		return go;
	}
	else if (Point == point{ 60,34 }) {
		std::vector <point> go{ {80,45}, {21,23} };
		return go;
	}
	else if (Point == point {20,55} ) {
		std::vector <point> go{ { 4,75 }, {21,23} };
		return go;
	}
	else if (Point == point{ 65,73 }) {
		std::vector <point> go{ {22,74} } ;
		return go;
	}
	else if (Point == point{ 21,23 }) {
		std::vector <point> go{ {20,55}, { 60,34 } };
		return go;
	}
} 
/*std::map <point, std::string> locations{ {{4,75},"Sun fontain"},{{198,4},"Moon fontain"},{{80,45}, "mid sun tower2"},{{40,57},"mid sun tower1"},{{60,34},"troika"},{{81,65},"forest"},{{20,55},"top sun tower1"},{{21,23},"top sun tower2"},{{22,74},"niz sun tower1"},{{65,70},"niz sun tower2"} };*/

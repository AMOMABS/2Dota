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

std::vector <Tower*> towers2{ new Tower({"t1_mid_s","sun",2500,100,Sun_mid_tower1}),
	   new Tower{"t2_mid_s","sun",1500,60,Sun_mid_tower2},
	   new Tower{"t1_top_s","sun",2500,100,Sun_top_tower1},
	   new Tower{"t2_top_s","sun",1500,60,Sun_top_tower2},
	   new Tower{"t1_niz_s","sun",2500,100,Sun_niz_tower1},
	   new Tower{"t2_niz_s","sun",1500,60,Sun_niz_tower2},
	   new Tower{"t1_mid_m","moon",2500,100,Moon_mid_tower1},
	   new Tower{"t2_mid_m","moon",1500,60,Moon_mid_tower2},
	   new Tower{"t1_top_m","moon",2500,100,Moon_top_tower1},
	   new Tower{"t2_top_m","moon",1500,60,Moon_top_tower2},
	   new Tower{"t1_niz_m","moon",2500,100,Moon_niz_tower1},
	   new Tower{"t2_niz_m","moon",1500,60,Moon_niz_tower2},
};

HeroModel::HeroModel() :pers("", nullptr, "", 500, 500,{-1,-1},1,0), names({"Jonny", "Stacy", "Monesy", "Morgen", "Bob", "Rafael","Pivozavr"}) {
	addHero(new Magnus());
	addHero(new Invoker());
	addHero(new PhantomAssasin());
	addHero(new ShadowFiend());
	addHero(new AntiMage());
	addHero(new Pudge());
	addThing(new Boots());
	addThing(new ArcaneBoots());
	addThing(new Radiance());
	this->towers = towers2;
	
}
HeroModel::~HeroModel() {
	for (auto& x : players) {
		delete x;
	}
	for (auto& x : heroes) {
		delete x;
	}
	for (auto& x : shopList) {
		delete x;
	}
	for (auto& x : towers) {
		delete x;
	}
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
	players.clear();
	int y;
	int x;
	do {
		y = rand() % newHeroes.size();
		x = rand() % names.size();
		if (moonCount < heroes.size() / 2) {
			players.push_back(new Person{ names[x],newHeroes[y],teams[0],0,500,{198,4},1,0 });
			moonCount++;
		}
		else {
			players.push_back(new Person{ names[x],newHeroes[y],teams[1],0,500,{4,75},1,0 });
			sunCount++;
		}
		deleteHero(newHeroes[y]);
	} while (newHeroes.size()>0);
}

void HeroModel::deleteHero(AbstractHero* hero) {
	newHeroes.erase(find(newHeroes.begin(), newHeroes.end(), hero));
}

void HeroModel::createNewHeroes() {
	newHeroes.clear();
	newHeroes.resize(heroes.size());
	for (int i = 0; i < heroes.size(); i++){
		newHeroes[i] = heroes[i];
	}
	for (int i = 0; i < newHeroes.size(); i++) {
		newHeroes[i]->setHp(heroes[i]->get_info().maxHp);
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

void HeroModel::botsMovement() {
	for (int i = 0; i < players.size(); i++) {
		int temp = rand() % 2;
		if (temp == 0) {
			std::vector <point> possibleGo = possibility(players[i]->getPersPoint());
			temp = rand() % possibleGo.size();
			players[i]->setPersPoint(possibleGo[temp].x, possibleGo[temp].y);
		}
		else {
			continue;
		}
	}
}

void HeroModel::addAtributes(Person& pers, AbstractThings* thing) {
	pers.getPersHero()->setAtributes(thing->getInfo().hp, thing->getInfo().mana,thing->getInfo().hp, thing->getInfo().mana, thing->getInfo().plusForce, thing->getInfo().plusAgility, thing->getInfo().plusIntelligence, thing->getInfo().plusAttackSpeed, thing->getInfo().plusAttackDamage, thing->getInfo().plusMoveSpeed);
}

Tower* HeroModel::haveTower(const Person& pers) {
	for (int i = 0; i < towers.size(); i++) {
		if ((pers.getPersPoint() == towers[i]->getPoint()) && (pers.getTeam() != towers[i]->getTeam())) {
			return towers[i];
		}
	}
	return nullptr;
	/*fazer depois de realizacao do fight, depois de muda de position em botsMove,ent e movement do Person*/
}

Person* HeroModel::havePerson(const Person& pers) {
	for (int i = 0; i < players.size(); i++) {
		if ((pers.getPersPoint() == players[i]->getPersPoint()) && (pers.getTeam() != players[i]->getTeam())) {
			return players[i];
		}
	}
	return nullptr;
}
std::vector<point> HeroModel::possibility(const point& Point) {
	if ((Point == Sun_niz_tower1)) {
		std::vector <point> go{ Sun_niz_tower2, Sun_fontain,Sun_forest };
		return go;
	}
	else if ((Point == Sun_fontain)) {
		std::vector <point> go{ Sun_mid_tower1,Sun_niz_tower1,Sun_top_tower1 };
		return  go;
	}
	else if ((Point == Sun_mid_tower1)) {
		std::vector <point> go{ Sun_mid_tower2 ,Sun_fontain };
		return go;
	}
	else if ((Point == Sun_mid_tower2)) {
		std::vector <point> go{ Sun_mid_tower1,Sun_troika,Sun_forest,Moon_mid_tower2};
		return go;
	}
	else if ((Point == Sun_forest)) {
		std::vector <point> go{ Sun_mid_tower2,Sun_niz_tower1 };
		return go;
	}
	else if ((Point == Sun_troika)) {
		std::vector <point> go{ Sun_mid_tower2, Sun_top_tower2 };
		return go;
	}
	else if ((Point == Sun_top_tower1)) {
		std::vector <point> go{ Sun_fontain, Sun_top_tower2 };
		return go;
	}
	else if ((Point == Sun_niz_tower2)) {
		std::vector <point> go{ Sun_niz_tower1 } ;
		return go;
	}
	else if ((Point == Sun_top_tower2)) {
		std::vector <point> go{ Sun_top_tower1, Sun_troika };
		return go;
	}
	else if ((Point == Moon_fontain)) {
		std::vector <point> go{ Moon_top_tower1,Moon_niz_tower1, Moon_mid_tower1 };
		return go;
	}
	else if ((Point == Moon_top_tower1)) {
		std::vector <point> go{ Moon_fontain };
		return go;
	}
	else if ((Point == Moon_niz_tower1)) {
		std::vector <point> go{ Moon_fontain };
		return go;
	}
	else if ((Point == Moon_mid_tower1)) {
		std::vector <point> go{ Moon_fontain,Moon_mid_tower2 };
		return go;
	}
	else if ((Point == Moon_mid_tower2)) {
		std::vector <point> go{ Moon_mid_tower1,Sun_mid_tower2};
		return go;
	}
} 

std::vector<Tower*> HeroModel::getTowers() const {
	return towers;
}



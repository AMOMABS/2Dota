#include "heroController.h"

void HeroController::addHero(AbstractHero* heroname) {
	model.addHero(heroname);
}

void HeroController::showHeroes() {
	view.displayHeroes(model.getHeroes());
}

int HeroController::input() {
	char key = _getch();  
	return key-48;
}

void HeroController::persName(const std::string& name) {
	model.get_person().setName(name);
}

void HeroController::go(int x) {
	auto pers = model.get_person();
	auto v = model.possibility(pers.getPersPoint());
	if ((x <= 0) or (x > v.size())) {
		return;
	}
	pers.setPersPoint(v[x-1].x, v[x-1].y);
}

void HeroController::cases(int x) {
	
}

void HeroController::game() {
	int temp7;
	int temp62;
	int temp2;
	int temp3;
	int temp5;
	Tower* temp6;
	int counter = 0;
	bool flag(true);
	
	do {
		lvlCheck();
		auto start = std::chrono::high_resolution_clock::now();
		view.gameMenu();
		int temp = input();
		int temp4;
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		model.setGoldForPlayers((duration.count() + counter) / 10);
		counter = (duration.count() + counter) % 10;
		model.randomBuy();
		model.botsMovement();
		auto& person = model.get_person();
		auto towers = model.getTowers();

		switch (temp) {
		case(0):
			flag = false;
			break;
		case(1):
			view.profile(model.get_person().get_info());

			break;
		case(2):
			view.displayThings(model.getThings());
			temp2 = input();
			for (int i = 0; i < size(model.getThings()); i++) {
				if (temp2 - 1 == i) {
					
					do{
						view.thingInfo(model.getThings()[i]->getInfo());
						temp4 = input();
						if (temp4 == 2) {
							system("pause");
							break;
						}
						else if (temp4 == 1) {
							if (model.get_person().get_info().gold >= model.getThings()[i]->getInfo().cost) {
								model.get_person().setGold(-(model.getThings()[i]->getInfo().cost));
								model.addHeroThing(model.getThings()[i]);
								system("cls");
								view.print(1);
								model.addAtributes(model.get_person(), model.getThings()[i]);
								system("pause");
							}
							else {
								system("cls");
								view.print(2);
								system("pause");
							}
						}
						else {
							std::cout << "\nerror!";
						}
					} while (temp4 != 1);
					
				}
			}
			break;
		case(3):
			view.displayPlayers(model.getPlayers());
			temp3 = input();
			while (temp3 < 1 || temp3 > model.getPlayers().size()) {
				std::cout << "Invalid value\n";
				view.displayPlayers(model.getPlayers());
				temp3 = input();
			}
			
			view.profile(model.getPlayers()[temp3 - 1]->get_info());
			break;
		case(4):
			view.printMap(model.getPlayers(), model.get_person());
			system("pause");
			break;
		case(5):
			view.printGo(model.possibility(model.get_person().getPersPoint()));
			temp5 = input();
			go(temp5);
			break;

		case(6):
			temp6 = checkNearTowers(model.getTowers());
			

			if (temp6 != nullptr) {
				system("cls");
				while (person.getPersPoint() == temp6->getPoint()) {
					view.printFightTower(person, *temp6);
					temp62 = input();
					fightWithTower(person, *temp6, temp62);
					system("pause");
					if (isDie()) {
						flag = false;
						break;
					}
				}
			}
			else {
				view.fightPrint(2, &person, *towers[0]);
				system("pause");
			}
			break;
		case 7:
			std::map<std::string, std::vector<Person*>> nearPlayers = checkNearPerson();
			auto& person = model.get_person();
			auto personPoint = person.getPersPoint();
			auto personTeam = person.getTeam();

			if (nearPlayers.empty()) {
				view.fightPersPrint(1, &person, nearPlayers);
				system("pause");
			}
			else {
				std::string enemyTeam = (personTeam == "sun") ? "moon" : "sun";

				while (!nearPlayers[enemyTeam].empty() &&
					personPoint.x == nearPlayers[enemyTeam][0]->getPersPoint().x &&
					personPoint.y == nearPlayers[enemyTeam][0]->getPersPoint().y) {

					view.fightPersPrint(3, &person, nearPlayers);
					temp7 = input();
					fight(temp7);
					system("pause");
					isDieOutro();

					if (isDie()) {
						flag = false;
						break;
					}

					nearPlayers = checkNearPerson(); 
					personPoint = person.getPersPoint();

					if (nearPlayers[enemyTeam].empty()) {
						system("cls");

						if (personTeam == "sun") {
							for (Person* p : nearPlayers["sun"]) {
								p->setXp(500);
							}
						}
						else {
							for (Person* p : nearPlayers["moon"]) {
								p->setXp(500);
							}
						}

						person.setXp(400);
						view.fightPersPrint(0, &person, nearPlayers);
						system("pause");
						break;
					}
				}
			}
			break;
		}
		flag = youWin();
	} while (flag);
	
}
void HeroController::choice(int x) {
	switch (x) {
	case 0:
		view.exitGame();
		break;
	case 1:
		view.displayHeroes(model.getHeroes());
		system("pause");
		break;
	case 2:
		view.start();
		view.displayHeroes(model.getHeroes());
		view.choose();
		int y = input();
		while(y < 1 || y > 6) {
			std::cout << "Invalid value\n";
			view.choose();
			y = input();
		}
		model.get_person().setPersHero(model.getHeroes()[y - 1]);
		model.createNewHeroes();
		game();
		break;
	}
	
}
void HeroController::startgame() {
	
	view.hello();
	view.firstStep();
	std::string name;
	getline(std::cin,name);
	persName(name);
	while (true) {	
		view.menu();
		choice(input());
	}
	
}

void HeroController::fightWithTower(Person& pers, Tower& tower,int x) {
	int temp = rand() % model.possibility(model.get_person().getPersPoint()).size();
	auto* hero = pers.getPersHero();
	auto heroInfo = hero->get_info();
	int towerDamage = tower.getDamage();
	int heroAttack = heroInfo.attackDamage;
	float heroSpeed = heroInfo.attackSpeed;
	int heroHp = heroInfo.hp;

	switch (x) {
	case 1:
		hero->setHp(heroHp - towerDamage);
		pers.setPersPoint(model.possibility(pers.getPersPoint())[temp].x,
			model.possibility(pers.getPersPoint())[temp].y);
		view.fightPrint(3, &pers, tower);
		break;
	case 2:
		tower.setHp(tower.getHp() - (heroAttack * heroSpeed));
		hero->setHp(heroHp - towerDamage);
		view.fightPrint(1, &pers, tower);
		break;
	}
}

Tower* HeroController::checkNearTowers(std::vector <Tower*> towers) {
	decltype(auto) pers = model.get_person();
	for (int i = 0; i < towers.size(); i++) {
		
		if ((towers[i]->getPoint() == pers.getPersPoint()) && (towers[i]->getTeam() != pers.getTeam()) && (towers[i]->getHp() != 0)) {
			return towers[i];
		}
	}

	return nullptr;
}

std::map <std::string,std::vector <Person*>> HeroController::checkNearPerson() {
	auto pers = model.get_person();
	auto player = model.getPlayers();
	std::map <std::string, std::vector <Person*>> nearPlayers{
		{"sun",{}},
		{"moon",{}}
	};
	for (int i = 0; i < model.getPlayers().size(); i++) {
		
		if (player[i]->getPersPoint() == pers.getPersPoint()) {
			nearPlayers[player[i]->getTeam()].push_back(player[i]);
		}
	}
	if (pers.getTeam() == "moon") {
		if (nearPlayers["sun"].size() == 0) {
			return {};
		}
	}
	else {
		if (nearPlayers["moon"].size() == 0) {
			return {};
		}
	}
	return nearPlayers;
}


bool HeroController::isDie() {
	if (model.get_person().getPersHero()->get_info().hp <= 0) {
		system("cls");
		view.print(3);
		system("pause");
		return true;
	}
}

void HeroController::isDieOutro() {
	decltype(auto) players = model.getPlayers();

	for (int i = 0; i < players.size(); i++) {
		auto* player = players[i];
		auto* hero = player->getPersHero();
		auto heroInfo = hero->get_info();

		if (heroInfo.hp <= 0) {
			if (player->getTeam() == "moon") {
				player->setPersPoint(198, 4);
			}
			else {
				player->setPersPoint(4, 75);
			}
			hero->setHp(heroInfo.maxHp);
		}
	}
}

void HeroController::fight(int x) {
	Person& pers = model.get_person();
	int temp;
	decltype(auto) nearPersons = checkNearPerson();
	decltype(auto) persHero = pers.getPersHero();
	decltype(auto) persInfo = persHero->get_info();
	point newPoint = { 1,1 };
	decltype(auto) persAttack = persInfo.attackDamage * persInfo.attackSpeed;
	switch (x) {
		
	case 1:
		
		temp = rand() % 2;
		newPoint = model.possibility(pers.getPersPoint())[temp];
		if (temp == 0) {


			if (model.get_person().getTeam() == "moon") {
				for (int i = 0; i < nearPersons["sun"].size(); i++) {
					decltype(auto) enemyHero = nearPersons["sun"][i]->getPersHero();
					persHero->setHp(persInfo.hp - (enemyHero->get_info().attackDamage * enemyHero->get_info().attackSpeed));
				}
				for (int j = 0; j < nearPersons["moon"].size(); j++) {
					nearPersons["moon"][j]->setPersPoint(newPoint.x, newPoint.y);
				}
			}
			else {
				for (int i = 0; i < nearPersons["moon"].size(); i++) {
					decltype(auto) enemyHero = nearPersons["moon"][i]->getPersHero();
					persHero->setHp(persInfo.hp - (enemyHero->get_info().attackDamage * enemyHero->get_info().attackSpeed));
				}
				for (int j = 0; j < nearPersons["sun"].size(); j++) {
					nearPersons["sun"][j]->setPersPoint(newPoint.x, newPoint.y);
				}
			}

			system("cls");
			view.print(5);
			pers.setPersPoint(newPoint.x, newPoint.y);
		}
		else {
			system("cls");
			view.print(4);
			
		}
		break;
	case 2:
		if (model.get_person().getTeam() == "moon") {
			for (int i = 0; i < nearPersons["sun"].size(); i++) {
				decltype(auto) sunHero = nearPersons["sun"][i]->getPersHero();
				decltype(auto) sunInfo = sunHero->get_info();
				decltype(auto) sunAttack = sunInfo.attackDamage * sunInfo.attackSpeed;

				persHero->setHp(persInfo.hp - sunAttack);
				sunHero->setHp(sunInfo.hp - persAttack);

				for (int j = 0; j < nearPersons["moon"].size(); j++) {
					decltype(auto) moonHero = nearPersons["moon"][j]->getPersHero();
					decltype(auto) moonInfo = moonHero->get_info();
					decltype(auto) moonAttack = moonInfo.attackDamage * moonInfo.attackSpeed;

					moonHero->setHp(moonInfo.hp - sunAttack);
					sunHero->setHp(sunHero->get_info().hp - moonAttack);
				}
			}
		}
		else {
			for (int i = 0; i < nearPersons["moon"].size(); i++) {
				decltype(auto) moonHero = nearPersons["moon"][i]->getPersHero();
				decltype(auto) moonInfo = moonHero->get_info();
				decltype(auto) moonAttack = moonInfo.attackDamage * moonInfo.attackSpeed;

				persHero->setHp(persInfo.hp - moonAttack);
				moonHero->setHp(moonInfo.hp - persAttack);

				for (int j = 0; j < nearPersons["sun"].size(); j++) {
					decltype(auto) sunHero = nearPersons["sun"][j]->getPersHero();
					decltype(auto) sunInfo = sunHero->get_info();
					decltype(auto) sunAttack = sunInfo.attackDamage * sunInfo.attackSpeed;

					sunHero->setHp(sunInfo.hp - moonAttack);
					moonHero->setHp(moonHero->get_info().hp - sunAttack);
				}
			}
		}

		view.fightPersPrint(2, &pers, nearPersons);
		break;
	}
}
void HeroController::lvlCheck() {
	std::vector <Person*> pl = model.getPlayers();
	for (int i = 0; i < pl.size(); i++) {
		pl[i]->setXp(2);
		pl[i]->xpInLvl();
	}
	model.get_person().setXp(2);
	model.get_person().xpInLvl();
}

bool HeroController::youWin() {
	bool breakAndWin = true;
	bool breakAndLose = true;
	decltype(auto) towers = model.getTowers();
	decltype(auto) pers = model.get_person();
	decltype(auto) team = pers.getTeam();
	if (team == "moon") {
		for (int i = 0; i < towers.size(); i++) {
			if (!((towers[i]->getHp() <= 0) && (towers[i]->getTeam() == "sun"))) {
				breakAndWin = false;
			}
			
			if (!((towers[i]->getHp() <= 0) && (towers[i]->getTeam() == "moon"))) {
				breakAndLose = false;
			}
			
		}
	}
	else{
		for (int i = 0; i < towers.size(); i++) {
			if (!((towers[i]->getHp() <= 0) && (towers[i]->getTeam() == "moon"))) {
				breakAndWin = false;
			}
			if (!((towers[i]->getHp() <= 0) && (towers[i]->getTeam() == "sun"))) {
				breakAndLose = false;
			}

		}
	}
	if (breakAndLose == true) {
		system("cls");
		view.print(6);
		system("pause");
		return false;
	}
	else if (breakAndWin == true) {
		system("cls");
		view.print(7);
		system("pause");
		return false;
	}
	else {
		return true;
	}
	
}
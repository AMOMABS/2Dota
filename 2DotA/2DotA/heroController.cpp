#include "heroController.h"

void HeroController::addHero(AbstractHero* heroname) {
	model.addHero(heroname);
}

void HeroController::showHeroes() {
	view.displayHeroes(model.getHeroes());
}

int HeroController::input() {
	int choice;
	std::cin >> choice;
	std::cin.ignore();
	return choice;
}

void HeroController::persName(const std::string& name) {
	model.get_person().setName(name);
}

void HeroController::game() {
	int temp2;
	int temp3;
	bool flag(true);
	do {
		view.gameMenu();
		int temp = input();
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
					view.thingInfo(model.getThings()[i]->getInfo());
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
		}
		
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


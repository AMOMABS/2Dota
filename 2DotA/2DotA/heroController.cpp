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
	int counter = 0;
	bool flag(true);
	do {
		auto start = std::chrono::high_resolution_clock::now();
		view.gameMenu();
		int temp = input();
		int temp4;
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
		}

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		model.get_person().setGold(model.get_person().get_info().goldPlus * ((duration.count()+counter) / 10));
		counter = (duration.count()+counter) % 10;
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


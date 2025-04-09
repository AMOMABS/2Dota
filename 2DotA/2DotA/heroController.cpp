#include "heroController.h"

std::map <point, std::string> locations{ {{4,75},"Sun fontain"},{{198,4},"Moon fontain"},{{80,45}, "mid sun tower2"},{{40,57},"mid sun tower1"},{{60,34},"troika"},{{81,65},"forest"},{{20,55},"top sun tower1"},{{21,23},"top sun tower2"}, { { 22,74 },"niz sun tower1" },{{65,73},"niz sun tower2"} };

void HeroController::addHero(AbstractHero* heroname) {
	model.addHero(heroname);
}

void HeroController::showHeroes() {
	view.displayHeroes(model.getHeroes());
}

int HeroController::input() {
	/*int choice;
	std::cin >> choice;
	std::cin.ignore();
	return choice;*/
	char key = _getch();  
	return key-48;
}

void HeroController::persName(const std::string& name) {
	model.get_person().setName(name);
}

void HeroController::cases(int x) {
	
	switch (x) {
	case 1:
		model.get_person().setPersPoint(model.possibility(model.get_person().getPersPoint())[0].x, model.possibility(model.get_person().getPersPoint())[0].y);
		break;
	case 2:
		if (model.possibility(model.get_person().getPersPoint()).size() >= 2) {
			model.get_person().setPersPoint(model.possibility(model.get_person().getPersPoint())[1].x, model.possibility(model.get_person().getPersPoint())[1].y);
			
		}
		
	case 3:
		if (model.possibility(model.get_person().getPersPoint()).size() >= 3) {
			model.get_person().setPersPoint(model.possibility(model.get_person().getPersPoint())[2].x, model.possibility(model.get_person().getPersPoint())[2].y);

		}
		
	}
}

void HeroController::game() {
	int temp2;
	int temp3;
	int temp5;
	int counter = 0;
	bool flag(true);
	do {
		auto start = std::chrono::high_resolution_clock::now();
		view.gameMenu();
		int temp = input();
		int temp4;
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
		model.setGoldForPlayers((duration.count() + counter) / 10);
		counter = (duration.count() + counter) % 10;
		model.randomBuy();
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
			view.printGo(model.possibility(model.get_person().getPersPoint()), locations);
			temp5 = input();
			cases(temp5);

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




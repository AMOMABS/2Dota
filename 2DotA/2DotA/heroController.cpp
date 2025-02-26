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

void HeroController::choice(int x) {
	switch (x) {
	case 0:
		view.exitGame();
	case 1:
		view.displayHeroes(model.getHeroes());
	}
}
void HeroController::startgame() {
	
	view.hello();
	while (true) {
		
		view.menu();
		
		choice(input());
	}
	
}


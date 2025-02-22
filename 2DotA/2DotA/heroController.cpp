#include "heroController.h"

void HeroController::addHero(AbstractHero* heroname) {
	model.addHero(heroname);
}

void HeroController::showHeroes() {
	view.displayHeroes(model.getHeroes());
}

void HeroController::startgame() {
	view.hello();
}
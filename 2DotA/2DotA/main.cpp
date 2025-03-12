#include "heroController.h"
#include <iostream>

int main() {
	system("chcp 1251");
	system("cls");
	srand(time(0));
	HeroController controller;
	controller.startgame();
}
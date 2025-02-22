#include "heroView.h"
#include <iostream>
#include <Windows.h>

void HeroView::displayHeroes(const std::vector<AbstractHero*>& heroes) {
	std::cout << "Список героев: " << std::endl;
	for (const AbstractHero* hero : heroes) {
		std::cout << hero->get_name() << std::endl;
	}
	std::cout << std::endl;
}

void HeroView::hello() {
	system("chcp 1251");
	system("cls");

	std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";

	const std::string name_of_the_game = "2DotA";

	for (const auto& c : name_of_the_game) {
		std::cout << c;
		Sleep(100);
	}

	std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";

	const std::string cont = "Нажмите любую клавишу чтобы продолжить";

	for (const auto& c : cont) {
		std::cout << c;
		Sleep(100);
	}

	std::cout << "\n\n\n";
	system("pause");
}
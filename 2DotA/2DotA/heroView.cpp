#include "heroView.h"
#include <iostream>
#include <Windows.h>

void HeroView::displayHeroes(const std::vector<AbstractHero*>& heroes) {
	std::cout << "������ ������: " << std::endl;
	for (const AbstractHero* hero : heroes) {
		std::cout << hero->get_name() << std::endl;
	}
	std::cout << std::endl;
}

void HeroView::hello() {
	

	std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";

	const std::string name_of_the_game = "2DotA";

	for (const auto& c : name_of_the_game) {
		std::cout << c;
		Sleep(100);
	}

	std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";

	const std::string cont = "������� ����� �������, ����� ����������";

	for (const auto& c : cont) {
		std::cout << c;
		Sleep(100);
	}

	std::cout << "\n\n\n";
	system("pause");
}

void HeroView::menu(){
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	std::cout << "������� �� �����, ����� ������� ��������:\n";
	std::cout << "0.�����\n";
	std::cout << "1.������ ������\n";
	std::cout << "2.������ ����\n";
	std::cout << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	std::cout << "�����:\n";
	
}

void HeroView::exitGame() {
	system("cls");
	std::cout << " ������������� �����";
	exit(0);
}



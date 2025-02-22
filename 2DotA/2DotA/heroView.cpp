#include "heroView.h"
#include <iostream>
#include <Windows.h>

void HeroView::displayHeroes(const std::vector<AbstractHero*>& heroes) {
	std::cout << "Ñïèñîê ãåðîåâ: " << std::endl;
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

	const std::string cont = "ÍÀÆÌÈÒÅ ËÞÁÓÞ ÊËÀÂÈØÓ, ×ÒÎÁÛ ÏÐÎÄÎËÆÈÒÜ";

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
	std::cout << "Íàæìèòå íà öèôðó, ÷òîáû âûáðàòü äåéñòâèå:\n";
	std::cout << "0.Âûõîä\n";
	std::cout << "1.Ñïèñîê ãåðîåâ\n";
	std::cout << "2.Íà÷àòü èãðó\n";
	std::cout << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	std::cout << "ÂÛÁÎÐ:\n";
	
}

void HeroView::exitGame() {
	system("cls");
	std::cout << " Âîçâðàùàéòåñü ñíîâà";
	exit(0);
}



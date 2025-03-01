#include "heroView.h"
#include <iostream>
#include <Windows.h>

void HeroView::displayHeroes(const std::vector<AbstractHero*>& heroes) {
	system("cls");
	
	
	for (int i = 0; i < heroes.size();i++) {
		std::cout << i+1 << "." << heroes[i]->get_name() << std::endl;
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
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	
	std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";

	const std::string frase = "Âîçâðàùàéòåñü ñíîâà!";

	for (const auto& c : frase) {
		std::cout << c;
		Sleep(100);
	}

	std::cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	exit(0);
}

void HeroView::firstStep() {
	system("cls");
	std::cout << "Input your name: ";
}

void HeroView::start() {
	system("cls");
	std::cout << "Choose your hero:\n";
}

void HeroView::choose() {
	std::cout << "//////////////////////////////\n";
	std::cout << "Choose(input number):";
}

void HeroView::gameMenu() {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	std::cout << "Game menu(choose):\n";
	std::cout << "0.Exit game\n";
	std::cout << "1.Profile\n";
	std::cout << "2.Shop\n";
	std::cout << "3.Map\n";
	std::cout << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	std::cout << "Choice:\n";
}

void HeroView::profile(Person::personData ps) {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	auto hero = ps.hero->get_info();
	std::cout << "\n";
	std::cout << "Info:\n";
	std::cout << "\n";
	std::cout << "Name:" << ps.name <<"\n";
	std::cout << "Hero data:\n";
	std::cout << "\n";
	std::cout << "hero: " << hero.name << std::endl;
	std::cout << "hp: " << hero.hp << std::endl;
	std::cout << "mana: " << hero.mana << std::endl;
	std::cout << "force: " << hero.force << std::endl;
	std::cout << "agility: " << hero.agility << std::endl;
	std::cout << "intelligence: " << hero.intelligence << std::endl;
	std::cout << "attackSpeed: " << hero.attackSpeed << std::endl;
	std::cout << "attackDamage: " << hero.attackDamage << std::endl;
	std::cout << "moveSpeed: " << hero.moveSpeed << std::endl;
	std::cout << "gold:" << ps.gold << std::endl;
	std::cout << "gold plus:" << ps.goldPlus << std::endl;
	std::cout << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	system("pause");
}


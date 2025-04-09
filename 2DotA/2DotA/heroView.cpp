#include "heroView.h"
#include <iostream>
#include <Windows.h>
#include <map>

std::map <point, std::string> locations1{ {{4,75},"Sun fontain"},{{198,4},"Moon fontain"},{{80,45}, "mid sun tower2"},{{40,57},"mid sun tower1"},{{60,34},"troika"},{{81,65},"forest"},{{20,55},"top sun tower1"},{{21,23},"top sun tower2"},{{22,74},"niz sun tower1"},{{65,73},"niz sun tower2"} };

const std::string temp1 = "moon";
const std::string temp2 = "sun";

std::vector<std::string> Map;
const std::vector<std::string> Map2{ "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
"@%                                                                                                                                   @                    @.                                           @",
"@%                                                                                                                                   @                   /@                                            @",
"@%                                                                                                                                   @                   @@                                            @",
"@%         ...............%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#                  @*                                            @",
"@%          @.                                                                                                                       @#                  @*                                            @",
"@%          @.                                                                                                                       @#                  @@                                            @",
"@%          @.                                                                                                                       @#                  /@                                            @",
"@%          @.                                                                                                                       @#                   @@                                           @",
"@%          @.                                                                                                                       @#                    @                                           @",
"@%          @.                                                                                                                       @@                    #@                                          @",
"@%          @.               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@###################################################@@                     .@.                                        @",
"@%          @.               @@                                                                                                      @@                       @@                                       @",
"@%          @.               @@                                                                                                      @@                        %@*                                     @",
"@%          @.               @@  ,@((((((((@@                                                                                        @@                          @@.                                   @",
"@%          @.               @@  ,@        @@                                                                                        @@                            *@@                                 @",
"@%          @.               @@  ,@        @@                                                   (@@.    *@@(                          @                               @@#                              @",
"@%          @.               @@                                                                %@          @*                        .@                                  /@@@@                         @",
"@%          @.               @@                                                                 /@@%   *&@@,                         .@%                                      @@@@@@                   @",
"@%          @.               @@                                                                     /  @#                               @@/                                        @@@@@@@@@@@@@@@@@@@@@",
"@%          @.               @@                                                                     @  @                               *@@ @@.                                                         @",
"@%          @.               *@                                                                     @  @                             @@.     ,@@                                                       @",
"@%          @.               *@                                                                     &  (,                         &@@           @@%                                                    @",
"@%          @.               *@                                                                    %@   ,                      (@@                 @@                                                  @",
"@%          @.               *@                       #%%%%                                    .%%   ,,   %@                 @@                      .@@                                               @",
"@%          @.               *@                &@@@.          ,@@@@                                                       @@,                           @@&                                            @",
"@%          @.               *@            &@@                     .@@(                                                &@@                           /@@   @@                                          @",
"@%          @.               *@          @@                            @@                                            @@                            @@        .@@&&&&&&&&&&@                @@@@@@@@@@@@@",
"@%          @@               *@        @@                                @@                                       @@                            @@@                       @                @           @",
"@%          @@               *@      .@                                   ,@                                   @@@                            @@                          @                @           @",
"@%          @@               *@     &@                                     /@.                              (@@                            @@,                            @                @           @",
"@%          @@               *@     @                                       #@                            @@                             @@                               @(               @           @",
"@%          @@               *@    #@                                        @                         @@                             @@,                                 @(               @&          @",
"@%          @@               *@    @@                                        @@                     &@@                            #@&       &@@@@@@@@@@                  @#               @&          @",
"@%          @@               *@    @@                                        @@                   @@                             @@     %@@               @@@             @#               @&          @",
"@%          @@               *@    #@                                        @                 @@                             #@@    @@/                     *@@          @#               @&          @",
"@%          @@               *@     @@                                      @@              @@@                             @@     %@                           @@        @(               @&          @",
"@%          @@               *@      @@                                    @@            .@@                             (@&      @*                             ,@       @#               @&          @",
"@%          @@               *@       &@                                 .@/           @@                             .@@        @                                 @.     @#               @&          @",
"@%          @@               *@         @@                             .@@          @@%                             @@.         @%                                 #@     @@               @@          @",
"@%          @@                @,          &@(                        @@*         %@@                             .@@           .@                                   @@    @@               @@          @",
"@%          @@                @,             #@@#                /@@           @@                              @@,             %@                                   @@    @@               @@          @",
"@%          @@                @,                  #@@@@@@@@@@@&.            @@                              .@@                 @                                   @#    @@               @@          @",
"@%          @@                @,                                         @@&         /||\\                 @@                    @%                                 #@     @@               @@          @",
"@%          @@                @,                                      *@@             ||               %@#                       @,                               .@.     @@               @@          @",
"@%          @@                @,                                    @@                ||             @@                           @#                             (@       @@               @@          @",
"@%          @@                @,                                 @@%                              #@#                              &@                           @@        @@               @@          @",
"@%          @@                @,                              %@@                               @@                                   (@%                     #@#          .@                @          @",
"@%          @@                @,                            @@                               @@.                                        (@@(             (@@(             .@                @          @",
"@%          @@                @,                         @@                               *@@                                                /(@@@@@@@@/                  .@                @          @",
"@@((((((((((((((((((((((((((((@(((@@@@@@@@@@@.        @@&                               @@.                                                                               .@                @          @",
"@%                                           @@    .@@                               *@@                                                                                  .@                @          @",
"@%                                             @@@@                                @@.                                                                                    .@                @          @",
"@%                                               @@                             &@*                                                                                       .@                @          @",
"@%                                                 @@                         @@                                                                                          .@                @          @",
"@%                                                   @@                    &@*                                                                                             @*               @#         @",
"@%                                                     @@                @@                                                                                                @*               @#         @",
"@%                                                       @@           &@/                                                                                                  @*               @#         @",
"@%*@@@@@@@@@@@@@@@@@@@@@@(@@@@&                            @@      (@@                          @&     @@                                                                  @*               @#         @",
"@%                              .@@@                         @@  @@                             @@&   @@@                                                                  @*               @#         @",
"@%                                   @@&                       @@                                  @ @                                                                     @*               @#         @",
"@%                                      %@%                      @@                                @ @                                                                     @*               @#         @",
"@%                                         @@                      @                               @ @                                                      @@@@@@@@@@     @*               @@         @",
"@%                                           @@                      @                             @  @                                                     @#       @     @@               @@         @",
"@%                                             @@                    @#                       /       *                                                     @#       @     @@               @@         @",
"@%                                              @@                   @#                                                                                                    @@               @@         @",
"@%                                               %@                  @#                                                                                                    @@               @@         @",
"@%                                                @@                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.              @@         @",
"@%                                                 @#                @#                                                                                                                     @@         @",
"@%                                                 @@                @@                                                                                                                     @@         @",
"@%                                                 .@                @@                                                                                                                     .@         @",
"@%                                                 .@                @@                                                                                                                     .@         @",
"@%                                                 @@                @@                                                                                                                     .@         @",
"@%                                                 @#                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/        @",
"@%                                                @@                 @@                                                                                                                                @",
"@%                                               %@                  .@                                                                                                                                @",
"@%                                              @@                    @                                                                                                                                @",
"@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",
};

void HeroView::displayHeroes(const std::vector<AbstractHero*>& heroes) {
	system("cls");
	std::cout << "Heroes:\n";
	for (int i = 0; i < heroes.size();i++) {
		std::cout << i+1 << "." << heroes[i]->get_name() << std::endl;
	}
	std::cout << std::endl;
}

void HeroView::displayPlayers(const std::vector<Person*>& players) {
	system("cls");
	std::cout << "Players:\n";
	for (int i = 0; i < players.size(); i++) {
		std::cout << i + 1 << "." << players[i]->getName() << std::endl;
	}
	std::cout << "Number:" << std::endl;
	
}

void HeroView::displayInv(AbstractHero* hero) {
	std::cout << "\nInventory:\n";
	for (int i = 0; i < hero->get_inv().size(); i++) {
		std::cout << i + 1 << "." << hero->get_inv()[i]->getName() << std::endl;
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
	std::cout << "3.Players info\n";
	std::cout << "4.Map\n";
	std::cout << "5.Go\n";
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
	SetConsoleTextAttribute(console, FOREGROUND_BLUE);
	auto hero = ps.hero->get_info();
	std::cout << "\n";
	std::cout << "Info:\n";
	std::cout << "\n";
	std::cout << "Name:" << ps.name <<"\n";
	std::cout << "Team:" << ps.team << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
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
	std::cout << "location:" << "x = " << ps.persPoint.x << ", y = " << ps.persPoint.y << ", " << locations1[ps.persPoint] << std::endl;
	displayInv(ps.hero);
	std::cout << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	std::cout << "////////////////////////////////////////////\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\n";
	system("pause");
}

void HeroView::shopMenu() {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	std::cout << "                                             \\\\SHOP//\n\n\n";
	
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void HeroView::displayThings(const std::vector<AbstractThings*>& things) {
	HeroView::shopMenu();
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE);
	for (int i = 0; i < things.size(); i++) {
		std::cout << "                                          " << i + 1 << "." << things[i]->getName() << std::endl;
	}
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\nChoice: ";
	std::cout << std::endl;
}

void HeroView::thingInfo(AbstractThings::thingData data) {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	
	std::cout << "                                             \\\\DATA//\n\n\n";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE); 
	std::cout << "                                          Name: " << data.name << std::endl;
	std::cout << "                                          Description: " << data.description << std::endl;
	
	if (data.hp != 0) {
		std::cout << "                                          +Hp: " << data.hp << std::endl;
	}
	if (data.mana != 0) {
		std::cout << "                                          +Mana: " << data.mana << std::endl;
	}
	if (data.plusForce != 0) {
		std::cout << "                                          +Force: " << data.plusForce << std::endl;
	}
	if (data.plusAgility != 0) {
		std::cout << "                                          +Agility: " << data.plusAgility << std::endl;
	}
	if (data.plusIntelligence != 0) {
		std::cout << "                                          +Intelligence: " << data.plusIntelligence << std::endl;
	}
	if (data.plusAttackSpeed != 0) {
		std::cout << "                                          +AttackSpeed: " << data.plusAttackSpeed << std::endl;
	}
	if (data.plusAttackDamage != 0) {
		std::cout << "                                          +AttackDamage: " << data.plusAttackDamage << std::endl;
	}
	if (data.plusMoveSpeed != 0) {
		std::cout << "                                          +MoveSpeed: " << data.plusMoveSpeed << std::endl;
	}
	if (data.radius != 0) {
		std::cout << "                                          Radius:" << data.radius << std::endl;
	}
	if (data.cost != 0) {
		std::cout << "                                          Cost: " << data.cost << std::endl;
	}

	std::cout << "\n1.Buy\n2.Back\nChoice:";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void HeroView::print(int x) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (x) {
	case(1):
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               Success!\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case(2):
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               Not enough gold, try more later...\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	}
}
void HeroView::printMap(std::vector<Person*> players, const Person& pers) {
	system("cls");
	Map = Map2;
	
	
	if (pers.getTeam() == temp1) {
		Map[pers.getPersPoint().y].replace(pers.getPersPoint().x-10, 3, "you");
		for (int i = 0; i < players.size(); i++) {
			if (players[i]->getTeam() == temp1) {
				Map[players[i]->getPersPoint().y].replace(pers.getPersPoint().x - 10, players[i]->getName().length(), players[i]->getName());
				
			}
		}
	}
	else {
		Map[pers.getPersPoint().y].replace(pers.getPersPoint().x+10, 3, "you");
		for (int i = 0; i < players.size(); i++) {
			if (players[i]->getTeam() == temp2) {
				Map[players[i]->getPersPoint().y ].replace(pers.getPersPoint().x + 10, players[i]->getName().length(), players[i]->getName());
				
			}
		}
	}
	
	for (auto& x : Map) {
		std::cout << x << std::endl;
	}
}

void HeroView::printGo(std::vector <point> go,std::map <point,std::string> locations) {
	system("cls");
	for (int i = 0; i < go.size(); i++) {
		std::cout << i + 1 << "." << locations[go[i]] << std::endl;
	}
	std::cout << "Choice:";
}
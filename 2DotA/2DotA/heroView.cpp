#include "heroView.h"
#include <iostream>
#include <Windows.h>
#include <map>

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
	std::cout << "6.Fight with tower\n";
	std::cout << "7.Fight with enemies\n";
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
	std::cout << "LVL:" << ps.lvl << std::endl;
	std::cout << "Xp for next LVL:" << ps.preXp - ps.xp << std::endl;
	std::cout << "location:" << "x = " << ps.persPoint.x << ", y = " << ps.persPoint.y << ", " << locations1.find(ps.persPoint)->second << std::endl;
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
	case(3):
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               YOU DIE...\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 4:
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               UNLUCK\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 5:
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               LUCKY\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 6:
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               YOU LOSE\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 7:
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               YOU WIN GAME, CONGRATULATIONS\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	}

}
void HeroView::printMap(const std::vector<Person*>& players, const Person& pers) {
	system("cls");
	Map = Map2;
	int counter = 1;
	auto pos = pers.getPersPoint();
	
	if (pers.getTeam() == temp1) {
		Map[pos.y].replace(pos.x-10, 3, "you");
		for (int i = 0; i < players.size(); i++) {
			auto posP = players[i]->getPersPoint();
			if (players[i]->getTeam() == temp1) {
				Map[(posP.y)+counter].replace(posP.x - 10, players[i]->getName().length(), players[i]->getName());
				counter++;
				
			}
		}
	}
	else {
		Map[pos.y].replace(pos.x+10, 3, "you");
		for (int i = 0; i < players.size(); i++) {
			auto posP = players[i]->getPersPoint();
			if (players[i]->getTeam() == temp2) {
				Map[posP.y-counter].replace(posP.x + 10, players[i]->getName().length(), players[i]->getName());
				counter++;
				
			}
		}
	}
	
	for (auto& x : Map) {
		std::cout << x << std::endl;
	}
}

void HeroView::printGo(const std::vector <point>& go) {
	system("cls");
	for (int i = 0; i < go.size(); i++) {
		std::cout << i + 1 << "." << locations1.find(go[i])->second<< std::endl;
	}
	std::cout << "Choice:";
}

void HeroView::printFightTower(const Person& pers, const Tower& tower) {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE);
	std::cout << "////////////////////////////////////////////\n";
	auto hero = pers.getPersHero()->get_info();
	std::cout << "\n";
	std::cout << "My Info:\n";
	std::cout << "\n";
	std::cout << "Hp:" << hero.hp << "\n";
	std::cout << "Mana:" << hero.mana << "\n";
	std::cout << "Damage:" << hero.attackDamage << "\n";
	std::cout << "AttackSpeed:" << hero.attackSpeed << "\n";
	SetConsoleTextAttribute(console,FOREGROUND_RED);
	std::cout << "////////////////////////////////////////////\n";
	std::cout << "\n";
	std::cout << "Tower Info:\n";
	std::cout << "\n";
	std::cout << "Hp:" << tower.getHp() << "\n";
	std::cout << "Damage:" << tower.getDamage() << "\n";
	std::cout << "AttackSpeed: 2" << "\n";
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE);
	std::cout << "What will you do?" << "\n";
	std::cout << "1.Run away(random position)" << "\n";
	std::cout << "2.Attack" << "\n";
	

}

void HeroView::fightPrint(int x, Person* pers, Tower tower) {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (x) {
	case(1):
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               You have dealt " << pers->getPersHero()->get_info().attackDamage << " and get" << tower.getDamage() << "!\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case(2):
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               Now it is no possible\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case(3):
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               You run away on random point!\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	}
}

void HeroView::fightPersPrint(int x, Person* pers, std::map <std::string, std::vector <Person*>> players) {
	system("cls");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (x) {
	
	case(0):
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               You win fight!!!\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case(1):
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               Now it is no possible\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case(2):
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n                                               You have dealt para cada inimigo " << (pers->getPersHero()->get_info().attackDamage) * (pers->getPersHero()->get_info().attackSpeed) << " and get" << pers->getPersHero()->get_info().maxHp - pers->getPersHero()->get_info().hp << "!\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		break;
	case 3:
		system("cls");
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
		std::cout << "////////////////////////////////////////////\n";
		auto hero = pers->getPersHero()->get_info();
		std::cout << "\n";
		std::cout << "My Info:\n";
		std::cout << "\n";
		std::cout << "Hp:" << hero.hp << "\n";
		std::cout << "Mana:" << hero.mana << "\n";
		std::cout << "Damage:" << hero.attackDamage << "\n";
		std::cout << "AttackSpeed:" << hero.attackSpeed << "\n\n";
		SetConsoleTextAttribute(console, FOREGROUND_BLUE);
		std::cout << "SUN:\n";
		auto s = players["sun"];
		for (int i = 0; i < s.size(); i++) {
			std::cout << "Name:" << s[i]->getName() << "\n";
			std::cout << "Hero:" << s[i]->getPersHero()->get_name() << "\n";
			std::cout << "Hp:" << s[i]->getPersHero()->get_info().hp << "\n";
			std::cout << "Mana:" << s[i]->getPersHero()->get_info().mana << "\n";
			std::cout << "Damage:" << s[i]->getPersHero()->get_info().attackDamage << "\n";
			std::cout << "AttackSpeed:" << s[i]->getPersHero()->get_info().attackSpeed << "\n";
		}
		std::cout << "\n";
		SetConsoleTextAttribute(console, FOREGROUND_RED);
		std::cout << "\nMOON:\n";
		auto m = players["moon"];
		for (int i = 0; i < m.size(); i++) {
			std::cout << "Name:" << m[i]->getName() << "\n";
			std::cout << "Hero:" << m[i]->getPersHero()->get_name() << "\n";
			std::cout << "Hp:" << m[i]->getPersHero()->get_info().hp << "\n";
			std::cout << "Mana:" << m[i]->getPersHero()->get_info().mana << "\n";
			std::cout << "Damage:" << m[i]->getPersHero()->get_info().attackDamage << "\n";
			std::cout << "AttackSpeed:" << m[i]->getPersHero()->get_info().attackSpeed << "\n";
		}
		std::cout << "\n1.Exit fight\n2.Attack\nChice:";


	}
}
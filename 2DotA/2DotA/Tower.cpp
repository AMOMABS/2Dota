#include "Tower.h"

Tower::Tower(std::string name,std::string team,int hp, int damage, point Point) : name(name),team(team),hp(hp), damage(damage), Point(Point){}

int Tower::getHp() const {
	return hp;
}
int Tower::getDamage() const {
	return damage;
}
void Tower::setHp(int newHp) {
	hp = newHp;
}
point Tower::getPoint() const {
	return Point;
}
std::string Tower::getTeam() {
	return team;
}

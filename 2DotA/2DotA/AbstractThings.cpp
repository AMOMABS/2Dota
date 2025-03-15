#include "AbstractThings.h"

AbstractThings::AbstractThings(std::string name, std::string description, int hp, int mana, float plusForce, float plusAgility, float plusIntelligence, int plusAttackSpeed, int plusAttackDamage, int plusMoveSpeed, int radius, int cost) :
	name(name), description(description), hp(hp), mana(mana), plusForce(plusForce), plusAgility(plusAgility), plusIntelligence(plusIntelligence), plusAttackSpeed(plusAttackSpeed), plusAttackDamage(plusAttackDamage), plusMoveSpeed(plusMoveSpeed), radius(radius), cost(cost) {
}

AbstractThings::thingData AbstractThings::getInfo() const {
	return thingData{ name, description, hp, mana, plusForce, plusAgility, plusIntelligence, plusAttackSpeed, plusAttackDamage, plusMoveSpeed, radius, cost };
}

std::string AbstractThings::getName() const {
	return name;
}
#pragma once
#include "AbstractThings.h"

class Boots : public AbstractThings {
public:
	Boots(std::string name = "Boots",std::string description = "", int hp = 0, int mana = 0, float plusForce = 0, float plusAgility = 0, float plusIntelligence = 0, int plusAttackSpeed = 0, int plusAttackDamage = 0, int plusMoveSpeed = 60, int radius = 0,int cost = 500) : AbstractThings(name, description, hp, mana, plusForce, plusAgility, plusIntelligence, plusAttackSpeed, plusAttackDamage, plusMoveSpeed, radius,cost) {}

	virtual void use() override {};

};

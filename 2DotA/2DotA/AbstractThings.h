#pragma once
#include <iostream>

class AbstractThings {
private:
	std::string name;
	std::string description;
	int plusHp;
	int plusMana;
	float plusForce;
	float plusAgility;
	float plusIntelligence;
	int plusAttackSpeed;
	int plusAttackDamage;
	int plusMoveSpeed;
	int radius;
public:
	AbstractThings(std::string Name, std::string description,int hp,int mana, float plusForce, float plusAgility, float pusIntelligence, int plusAttackSpeed, int plusAttackDamage, int plusMoveSpeed, int radius ) : 
		plusHp(plusHp), plusMana(plusMana), plusForce(plusForce), plusAgility(plusAgility), plusIntelligence(plusIntelligence), plusAttackSpeed(plusAttackSpeed), plusAttackDamage(plusAttackDamage),plusMoveSpeed(plusMoveSpeed), radius(radius){ }

	struct thingData {
		std::string name;
		std::string description;
		int plusHp;
		int plusMana;
		float plusForce;
		float plusAgility;
		float plusIntelligence;
		int plusAttackSpeed;
		int plusAttackDamage;
		int plusMoveSpeed;
		int radius;
	};

	virtual thingData getInfo(){
		return thingData{ name, description, plusHp, plusMana, plusForce, plusAgility, plusIntelligence, plusAttackSpeed, plusAttackDamage, plusMoveSpeed, radius };
	}

	virtual void use() = 0;
};

#pragma once
#include <iostream>

class AbstractThings {
private:
	std::string name;
	std::string description;
	int hp;
	int mana;
	float plusForce;
	float plusAgility;
	float plusIntelligence;
	int plusAttackSpeed;
	int plusAttackDamage;
	int plusMoveSpeed;
	int radius;
	int cost;
public:
	AbstractThings(std::string name, std::string description, int hp, int mana, float plusForce, float plusAgility, float plusIntelligence, int plusAttackSpeed, int plusAttackDamage, int plusMoveSpeed, int radius, int cost);

	struct thingData {
		std::string name;
		std::string description;
		int hp;
		int mana;
		float plusForce;
		float plusAgility;
		float plusIntelligence;
		int plusAttackSpeed;
		int plusAttackDamage;
		int plusMoveSpeed;
		int radius;
		int cost;
	};

	virtual thingData getInfo() const;

	virtual std::string getName() const;

	virtual void use() = 0;
};

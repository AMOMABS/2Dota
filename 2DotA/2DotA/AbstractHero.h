#pragma once
#include <string>
#include <vector>
#include "AbstractThings.h"
class AbstractHero {
private:
	std::string name;
	int hp;
	int mana;
	float force;
	float agility;
	float intelligence;
	int attackSpeed;
	int attackDamage;
	int moveSpeed;
	std::vector <AbstractThings*> inv;
public:
	AbstractHero(int hp, int mana,std::string name, float force, float agility, float intelligence, int attackSpeed, int attackDamage, int moveSpeed) :
		hp(hp),mana(mana),name(name), force(force), agility(agility), intelligence(intelligence), attackSpeed(attackSpeed), attackDamage(attackDamage), moveSpeed(moveSpeed){ }

	struct heroData {
		std::string name;
		int hp;
		int mana;
		float force;
		float agility;
		float intelligence;
		int attackSpeed;
		int attackDamage;
		int moveSpeed;
	};

	virtual std::string get_name() const{
		return name;
	}
	virtual heroData get_info() const{
		return heroData{ name,hp,mana,force,agility,intelligence,attackSpeed,attackDamage,moveSpeed };
	}
	virtual std::vector<AbstractThings*>& get_inv() {
		return inv;
	}

	virtual void skill1() = 0;

	
	virtual void ult() = 0;

	




};


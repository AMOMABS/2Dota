#include "AbstractHero.h"

AbstractHero::AbstractHero(int hp, int mana, std::string name, float force, float agility, float intelligence, int attackSpeed, int attackDamage, int moveSpeed) :
	hp(hp), mana(mana), name(name), force(force), agility(agility), intelligence(intelligence), attackSpeed(attackSpeed), attackDamage(attackDamage), moveSpeed(moveSpeed) {
}
std::string AbstractHero::get_name() const{
	return name;
}
AbstractHero::heroData AbstractHero::get_info() const{
	return heroData{ name,hp,mana,force,agility,intelligence,attackSpeed,attackDamage,moveSpeed };
}
std::vector<AbstractThings*> AbstractHero::get_inv() const{
	return inv;
}

void AbstractHero::setAtributes(int plushp, int plusmana, float plusForce, float plusAgility, float plusIntelligence, int plusattackspeed, int plusattackDamage, int plusmoveSpeed) {
	hp += plushp;
	mana += plusmana;
	force += plusForce;
	agility += plusAgility;
	intelligence += plusIntelligence;
	attackSpeed += plusattackspeed;
	attackDamage += plusattackDamage;
	moveSpeed += plusmoveSpeed;

}




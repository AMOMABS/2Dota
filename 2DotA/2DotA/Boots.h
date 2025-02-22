#pragma once
#include "AbstractThings.h"

class Boots : public AbstractThings {
public:
	Boots() : AbstractThings("Boots", "ботинок", 0,300,0,0,0,0,0,60,0){}

	virtual void use() override = 0;

};

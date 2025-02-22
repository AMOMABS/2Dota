#pragma once
#include "AbstractHero.h"

class PhantomAssasin : public AbstractHero {
public:
	PhantomAssasin() :
		AbstractHero(610, 350, "PHANTOM_ASSASIN", 2, 5, 1, 65, 60, 300) {
	}
	void skill1()  override {

	}
	void ult() override {

	}
};


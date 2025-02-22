#pragma once
#include "AbstractHero.h"

class Magnus : public AbstractHero {
public:
	Magnus() :
		AbstractHero(700, 410, "MAGNUS", 3, 3, 2, 55, 70, 330) {
	}
	void skill1()  override {

	}
	void ult() override {

	}
};



#pragma once
#include "AbstractHero.h"

class Pudge : public AbstractHero {
public:
	Pudge() :
		AbstractHero(780, 360, "PUDGE", 5, 1, 1, 50, 58, 280) {
	}
	void skill1()  override {

	}
	void ult() override {

	}
};

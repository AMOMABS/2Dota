#pragma once
#include "AbstractHero.h"

class AntiMage : public AbstractHero {
public:
	AntiMage() :
		AbstractHero(620, 420, "ANTI_MAGE", 2, 4, 2, 63, 65, 310) {
	}
	void skill1()  override {

	}
	void ult() override {

	}
};


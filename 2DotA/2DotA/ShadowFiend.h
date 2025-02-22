#pragma once
#include "AbstractHero.h"

class ShadowFiend : public AbstractHero {
public:
	ShadowFiend() :
		AbstractHero(650, 666, "SHADOW_FIEND", 2, 4, 3, 63, 60, 340) {
	}
	void skill1()  override {

	}
	void ult() override {

	}
};

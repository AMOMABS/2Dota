#pragma once
#include "AbstractHero.h"

class Invoker : public AbstractHero {
public:
	Invoker() :
		AbstractHero(650, 666, "INVOKER", 3, 3, 3, 60, 65, 280) {
	}
	void skill1()  override {

	}
	void ult() override {

	}
};
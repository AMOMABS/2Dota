#pragma once
#include "AbstractThings.h"

class Radiance : public AbstractThings {
public:
	Radiance() : AbstractThings("Radiance", "Good swor made in great AMerica", 0, 0, 0, 0, 0, 42, 1000, 0, 0, 4700) {}

	virtual void use() override {

	}

};

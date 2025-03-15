#pragma once
#include "AbstractHero.h"

class AntiMage : public AbstractHero {
public:
	AntiMage();
	void skill1()  override;
	void ult() override;
};


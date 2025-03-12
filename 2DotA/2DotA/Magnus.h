#pragma once
#include "AbstractHero.h"

class Magnus : public AbstractHero {
public:
	Magnus();
	void skill1()  override;
	void ult() override;
};



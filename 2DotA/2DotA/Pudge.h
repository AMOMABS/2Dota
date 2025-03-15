#pragma once
#include "AbstractHero.h"

class Pudge : public AbstractHero {
public:
	Pudge();
	void skill1()  override;

	
	void ult() override;

	
};

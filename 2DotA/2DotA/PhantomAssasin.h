#pragma once
#include "AbstractHero.h"

class PhantomAssasin : public AbstractHero {
public:
	PhantomAssasin();
	void skill1()  override;
	void ult() override;
	
};


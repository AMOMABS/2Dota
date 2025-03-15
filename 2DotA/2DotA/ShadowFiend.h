#pragma once
#include "AbstractHero.h"

class ShadowFiend : public AbstractHero {
public:
	ShadowFiend();
	void skill1()  override;
	void ult() override;
};

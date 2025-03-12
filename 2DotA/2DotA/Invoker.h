#pragma once
#include "AbstractHero.h"

class Invoker : public AbstractHero {
public:
	Invoker();
	void skill1()  override;
	void ult() override;
};
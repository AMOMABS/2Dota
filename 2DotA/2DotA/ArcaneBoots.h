#pragma once
#include "Boots.h"

class ArcaneBoots : public Boots {
public:
	ArcaneBoots() : Boots("Arcane Boots", "Good boots", 0, 300, 0, 3, 0, 0, 0, 60, 1000,1500) {}

	virtual void use() override{
		
	}

};


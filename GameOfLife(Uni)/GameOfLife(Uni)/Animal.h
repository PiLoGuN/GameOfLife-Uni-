#pragma once
#include "GridObject.h"
class Animal : public GridObject
{
public:
	void Update() override;
	int walkLifeLeft = 10000;
	int maxWalkLife = 10000;
	bool dead = false;
};


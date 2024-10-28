#pragma once
#include "Animal.h"

class Herbivore : public Animal
{
	public:
		void Update() override;
		Herbivore();
	private:
		bool AttackTarget(int, int);
};


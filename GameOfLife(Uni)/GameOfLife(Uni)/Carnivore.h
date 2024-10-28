#pragma once
#include "GridObject.h"
#include "Animal.h"


class Carnivore : public Animal
{
	public:
		void Update() override;
		Carnivore();
	private:
		bool AttackTarget(int, int);
};


#include <random>
#include <typeinfo>

#include "Herbivore.h"
#include "PopulationHandler.h"

Herbivore::Herbivore()
{
	id = 1;
}


bool Herbivore::AttackTarget(int x, int y)
{
	int targetId = PopulationHandler::FindTargetFromPosition(x, y);
	if (targetId == -1) return true;

	if (PopulationHandler::singleton().populatedObjects.at(targetId)->id != 2) return false;


	//if (typeid(Carnivore))
	walkLifeLeft = maxWalkLife;
	PopulationHandler::singleton().RemovePopulation(targetId);

	return true;
}

void Herbivore::Update()
{
	Animal::Update();

	if (dead) return;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> randomDir(0, 3);

	//TranslateObject(0, -1);
	int selectedDirection = randomDir(rng);

	if (selectedDirection == 0)
	{
		if (!AttackTarget(x + 1, y)) return;
		TranslateObject(1, 0);
	}
	else if (selectedDirection == 1)
	{
		if (!AttackTarget(x, y - 1)) return;
		TranslateObject(0, -1);
	}
	else if (selectedDirection == 2)
	{
		if (!AttackTarget(x - 1, y)) return;
		TranslateObject(-1, 0);
	}
	else
	{
		if (!AttackTarget(x, y + 1)) return;
		TranslateObject(0, 1);
	}
}
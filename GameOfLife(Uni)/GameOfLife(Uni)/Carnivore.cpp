#include <random>
#include <typeinfo>
#include <Windows.h>
#include <string>

#include "Carnivore.h"
#include "PopulationHandler.h"

bool Carnivore::AttackTarget(int xT, int yT)
{
	int targetId = PopulationHandler::FindTargetFromPosition(xT, yT);
	if (targetId == -1) return true;

	if (PopulationHandler::singleton().populatedObjects.at(targetId)->id != 1) return false;
	//OutputDebugStringA((LPCSTR)((to_string(PopulationHandler::singleton().populatedObjects.at(targetId)->id)).append("\n").c_str()));

	walkLifeLeft = maxWalkLife;

	//if (typeid(Carnivore))
	PopulationHandler::singleton().RemovePopulation(targetId);

	return true;
}

void Carnivore::Update()
{
	Animal::Update();

	if (dead) return;

	//if (!AttackTarget(x, y+1)) return;
	//TranslateObject(0, 1);
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> randomDir(0, 3);

	
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

Carnivore::Carnivore()
{
	id = 0;
	walkLifeLeft = 20;
	maxWalkLife = 20;
}
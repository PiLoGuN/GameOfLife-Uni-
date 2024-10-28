#include "Animal.h"
#include "PopulationHandler.h"


void Animal::Update()
{
	walkLifeLeft--;
	if (walkLifeLeft <= 0)
	{
		dead = true;
		PopulationHandler::singleton().RemovePopulation(PopulationHandler::FindTargetFromPosition(x, y));
	}
}
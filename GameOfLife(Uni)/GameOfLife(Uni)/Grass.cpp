#include "Grass.h"
#include "PopulationHandler.h"

void Grass::Update()
{
	updatesCount++;
	if (updatesCount > maxUpdatesCount)
	{
		PopulationHandler::singleton().RemovePopulation(PopulationHandler::FindTargetFromPosition(x,y));
	}
}

Grass::Grass()
{
	id = 2;
}

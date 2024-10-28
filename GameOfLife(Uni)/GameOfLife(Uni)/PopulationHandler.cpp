#include <random>

#include "PopulationHandler.h"
#include "GridHandler.h"

#include "Carnivore.h"
#include "Herbivore.h"
#include "Grass.h"

void PopulationHandler::SpawnObject(int id)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distPos(0, 9);

	for (size_t i = 0; i < 100; i++)
	{
		int randomX = distPos(rng);
		int randomY = distPos(rng);


		if (GridHandler::singleton().gridObjects[randomX][randomY] != -1) continue;

		GridHandler::singleton().gridObjects[randomX][randomY] = id;
		if (id == 0)
		{
			//populatedObjects.
			//populationObjects.

			Carnivore* carn = new Carnivore();

			carn->x = randomX;
			carn->y = randomY;
			
			populatedObjects.push_back(carn);
		}
		else if (id == 1)
		{
			Herbivore* herb = new Herbivore();

			herb->x = randomX;
			herb->y = randomY;

			populatedObjects.push_back(herb);
		}
		else if (id == 2)
		{
			Grass* grass = new Grass();

			grass->x = randomX;
			grass->y = randomY;

			grass->maxUpdatesCount = grassLifeTime;

			populatedObjects.push_back(grass);
		}

		break;
	}
}

PopulationHandler::PopulationHandler()
{
	for (size_t i = 0; i < carnivoreStartCount; i++)
	{
		SpawnObject(0);
	}
	for (size_t i = 0; i < herbivoreStartCount; i++)
	{
		SpawnObject(1);
	}
	
}

void PopulationHandler::GrassUpdate() 
{
	grassSpawnCurUpdateCount++;
	if (grassSpawnCurUpdateCount >= updatesPerGrassSpawn) 
	{
		grassSpawnCurUpdateCount = 0;
		for (size_t i = 0; i < grassCountPerUpdate; i++)
		{
			SpawnObject(2);
		}
	}
}

void PopulationHandler::UpdatePopulation()
{
	GrassUpdate();

	populatedObjects.shrink_to_fit();
	//for (auto it = populatedObjects.rbegin(); it != populatedObjects.rend(); ++it)
	//for (auto it = populatedObjects.begin(); it != populatedObjects.end(); it++)

	for (int i = populatedObjects.size()-1; i >= 0; i--)
	{
		//(*it)->Update();
		populatedObjects.at(i)->Update();
	}
}
void PopulationHandler::RemovePopulation(int id)
{
	if (id < 0) return;
	if (populatedObjects.size() < id+1) return;

	GridObject* object = populatedObjects.at(id);

	GridHandler::singleton().gridObjects[object->x][object->y] = -1;

	populatedObjects.erase(populatedObjects.begin()+id);

	delete object;
	//populatedObjects.shrink_to_fit();
}

void PopulationHandler::AddPopulation(GridObject* object)
{
	populatedObjects.push_back(object);
	//populatedObjects.shrink_to_fit();
}


int PopulationHandler::FindTargetFromPosition(int xIn, int yIn)
{
	PopulationHandler popSingleton = PopulationHandler::singleton();
	int i = 0;
	for (auto it = popSingleton.populatedObjects.begin(); it != popSingleton.populatedObjects.end(); it++)
	{
		if ((*it)->x == xIn && (*it)->y == yIn) return i;
		i++;
	}
	return -1;
}

PopulationHandler& PopulationHandler::singleton()
{
	if (!instance) {
		instance = new PopulationHandler();
	}
	return *instance;
}

PopulationHandler* PopulationHandler::instance;
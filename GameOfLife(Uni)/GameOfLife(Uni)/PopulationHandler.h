#pragma once

#include <vector>
using namespace std;

#include "GridObject.h"

class PopulationHandler
{
	public:
		int carnivoreStartCount = 10;
		int herbivoreStartCount = 10;
		int updatesPerGrassSpawn = 2;
		int grassCountPerUpdate = 3;
		int grassLifeTime = 10;

		vector<GridObject*> populatedObjects;

		static PopulationHandler& singleton();
		static int FindTargetFromPosition(int, int);

		void UpdatePopulation();
		void GrassUpdate();
		void AddPopulation(GridObject*);
		void RemovePopulation(int);
	private:
		void SpawnObject(int id);
		static PopulationHandler* instance;
		PopulationHandler();
		int grassSpawnCurUpdateCount;
};


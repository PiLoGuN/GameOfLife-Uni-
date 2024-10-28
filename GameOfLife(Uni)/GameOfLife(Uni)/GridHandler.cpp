#include "GridHandler.h"

//GridHandler::gridObjects = int[10][10];

GridHandler::GridHandler()
{
	for (size_t x = 0; x < gridSize; x++)
	{
		for (size_t y = 0; y < gridSize; y++)
		{
			gridObjects[x][y] = -1;
		}
	}
}

GridHandler& GridHandler::singleton()
{
    if (!instance) {
        instance = new GridHandler();
    }
    return *instance;
}

bool GridHandler::IsInbounds(int x, int y) 
{
	if (x < 0 || x > singleton().gridSize - 1) return false;
	if (y < 0 || y > singleton().gridSize - 1) return false;

	return true;
}

GridHandler* GridHandler::instance;

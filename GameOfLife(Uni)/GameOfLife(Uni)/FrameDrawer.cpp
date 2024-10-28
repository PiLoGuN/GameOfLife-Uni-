#include <iostream>

#include "FrameDrawer.h"
#include "GridHandler.h"

using namespace std;

void drawOutline() 
{
	int gridSize = GridHandler::singleton().gridSize;
	printf("\033[0;37m");
	for (size_t x = 0; x < gridSize + 3; x++)
	{
		printf("\033[%d;%dH", 0, x);
		cout << "-";
	}
	for (size_t x = 0; x < gridSize + 3; x++)
	{
		printf("\033[%d;%dH", gridSize+2, x);
		cout << "-";
	}
	for (size_t y = 0; y < gridSize + 3; y++)
	{
		printf("\033[%d;%dH", y, 0);
		cout << "|";
	}
	for (size_t y = 0; y < gridSize + 3; y++)
	{
		printf("\033[%d;%dH", y, gridSize+2);
		cout << "|";
	}
}

void drawObjects() 
{
	int gridSize = GridHandler::singleton().gridSize;

	for (size_t x = 0; x < gridSize; x++)
	{
		for (size_t y = 0; y < gridSize; y++)
		{
			if (GridHandler::singleton().gridObjects[x][y] == -1) 
			{
				printf("\033[%d;%dH", y + 2, x + 2);
				cout << " ";
				continue;
			}

			printf("\033[%d;%dH", y+2, x+2);
			if (GridHandler::singleton().gridObjects[x][y] == 0) 
			{
				printf("\033[0;31m");
				cout << "C";
			}
			else if (GridHandler::singleton().gridObjects[x][y] == 1)
			{
				printf("\033[0;36m");
				cout << "H";
			}
			else 
			{
				printf("\033[0;32m");
				cout << "G";
			}
			//cout << GridHandler::singleton().gridObjects[x][y];
		}
	}
}

void FrameDrawer::DrawMenu()
{
	int gridSize = GridHandler::singleton().gridSize;

	if (!tabMenu) return;
	if (tabMenu->menuState) 
	{
		printf("\033[0;37m");
		for (size_t x = 0; x < 15; x++)
		{
			printf("\033[%d;%dH", 0, x + gridSize + 5);
			cout << "-";
		}
		for (size_t x = 0; x < 15; x++)
		{
			printf("\033[%d;%dH", gridSize + 2, x + gridSize + 5);
			cout << "-";
		}
		for (size_t y = 0; y < gridSize + 3; y++)
		{
			printf("\033[%d;%dH", y, gridSize + 5);
			cout << "|";
		}
	}
	else 
	{
		printf("\033[0;37m");
		for (size_t x = 0; x < 15; x++)
		{
			printf("\033[%d;%dH", 0, x + gridSize + 5);
			cout << " ";
		}
		for (size_t x = 0; x < 15; x++)
		{
			printf("\033[%d;%dH", gridSize + 2, x + gridSize + 5);
			cout << " ";
		}
		for (size_t y = 0; y < gridSize + 3; y++)
		{
			printf("\033[%d;%dH", y, gridSize + 5);
			cout << " ";
		}
	}

	/*printf("\033[0;37m");
	for (size_t x = 0; x < 15; x++)
	{
		printf("\033[%d;%dH", 0, x + gridSize + 5);
		cout << "-";
	}
	for (size_t x = 0; x < 15; x++)
	{
		printf("\033[%d;%dH", gridSize + 2, x + gridSize + 5);
		cout << "-";
	}
	for (size_t y = 0; y < gridSize + 3; y++)
	{
		printf("\033[%d;%dH", y, gridSize + 5);
		cout << "|";
	}*/
	/*for (size_t y = 0; y < gridSize + 3; y++)
	{
		printf("\033[%d;%dH", y, gridSize + 7);
		cout << "|";
	}*/
}


void FrameDrawer::DrawFrame()
{
	drawOutline();
	drawObjects();
	DrawMenu();
}
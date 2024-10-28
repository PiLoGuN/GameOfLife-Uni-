#pragma once
class GridHandler
{
	public:
		int gridObjects[10][10];
		int gridSize = 10;
		static GridHandler& singleton();
		static bool IsInbounds(int x, int y);
	private:
		static GridHandler* instance;
		GridHandler();
};



#pragma once
class GridObject
{
	public:
		int x;
		int y;

		int id;
		virtual void Update() = 0;
	public:
		void TranslateObject(int, int);
};


#pragma once
#include "GridObject.h"

class Grass : public GridObject
{
	public:
		void Update() override;
		int updatesCount = 0;
		int maxUpdatesCount = 10;
		Grass();
};


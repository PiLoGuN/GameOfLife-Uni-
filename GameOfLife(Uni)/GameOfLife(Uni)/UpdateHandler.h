#pragma once
#include "FrameDrawer.h"
#include "PopulationHandler.h"
#include "TabMenu.h"


class UpdateHandler
{
	public:
		void CauseUpdate();
		int updateTime = 1;
		UpdateHandler();
	private:
		//PopulationHandler* populationHandler = new PopulationHandler();
		FrameDrawer* drawer = new FrameDrawer();
		TabMenu* menu = new TabMenu();
};


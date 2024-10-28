#include "UpdateHandler.h"

void UpdateHandler :: CauseUpdate()
{
	//populationHandler->UpdatePopulation();
	menu->UpdateKeypresses();
	if (!menu->menuState)
	{
		PopulationHandler::singleton().UpdatePopulation();
	}
	drawer->DrawFrame();
}

UpdateHandler::UpdateHandler()
{
	drawer->tabMenu = menu;
}

#pragma once
#include "TabMenu.h"


class FrameDrawer
{
	public:
		void DrawFrame();
		TabMenu* tabMenu;
	private:
		void DrawMenu();
};


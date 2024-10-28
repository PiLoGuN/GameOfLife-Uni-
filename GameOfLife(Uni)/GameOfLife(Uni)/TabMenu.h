#pragma once
class TabMenu
{
	public:
		void UpdateKeypresses();
		bool menuState;
	private:
		bool lastPressed;
		void EnableMenu();
};


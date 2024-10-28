#include <Windows.h>
#include <iostream>

#include "TabMenu.h"


void TabMenu::EnableMenu()
{

}


void TabMenu::UpdateKeypresses()
{
    if (GetKeyState(VK_TAB) & 0x8000) 
    {
        if (lastPressed) return;
        lastPressed = true;

        menuState = !menuState;
        /*if (menuState)
        {
            OutputDebugStringA((LPCSTR)("true\n"));
        }
        else 
        {
            OutputDebugStringA((LPCSTR)("false\n"));
        }*/
        if (menuState)
        {
            EnableMenu();
        }
    }
    else
    {
        lastPressed = false;
    }
}

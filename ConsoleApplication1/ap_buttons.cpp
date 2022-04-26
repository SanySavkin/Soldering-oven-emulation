#include "ap_buttons.h"
#include "Windows.h"



bool KeyBoard::IsPressed(uint32_t indx)
{
    switch (indx)
    {
    case 0:
        return GetKeyState('A') & 0x8000;
    case 1:
        return GetKeyState('D') & 0x8000;
    case 2:
        return GetKeyState('S') & 0x8000;
    case 3:
        return GetKeyState('W') & 0x8000;
    default:
        return false;
    }
}







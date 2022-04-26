#ifndef AP_BUTTONS_H
#define AP_BUTTONS_H


#include "stdint.h"


class KeyBoard
{
public:
    static bool IsPressed(uint32_t indx);
};



#endif //AP_BUTTONS_H

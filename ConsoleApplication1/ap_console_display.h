#ifndef AP_CONSOLE_DISPLAY_H
#define AP_CONSOLE_DISPLAY_H


#include "Display/idisplay.h"
#include "Windows.h"


#undef DrawText


class MainDisplay : public IDisplay
{
private:
    const char* profileName;
    int32_t maxTemp;
    int32_t totalTime;
    int32_t currentTemp;
    int32_t _x = 0;
    int32_t _y = 0;
    HANDLE hConsole = NULL;
public:
    MainDisplay();
    virtual void DrawPixel(uint32_t x, uint32_t y, uint8_t data) override;
    virtual void DrawText(uint16_t x, uint16_t y, const char* str, uint16_t len, uint8_t fontSize) override;
    virtual void DrawNumber(uint16_t x, uint16_t y, int32_t number, uint8_t fontSize)override; 
    virtual void DrawNumber(uint16_t x, uint16_t y, float number, uint8_t fontSize) override;
    virtual void FillRectangle(uint16_t xTop, uint16_t yTop, uint16_t xBot, uint16_t yBot, uint8_t color) override;
    virtual void DrawRectangle(uint16_t xleft, uint16_t yleft, uint16_t xRight, uint16_t yRight, uint8_t color) override;
    virtual void Update() override;
    virtual void Clear() override;
};




#endif //AP_CONSOLE_DISPLAY_H

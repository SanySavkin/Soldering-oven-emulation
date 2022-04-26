#include <iostream>
#include "ap_console_display.h"





MainDisplay::MainDisplay()
{
    currentTemp = 0;
    totalTime = 0;
    maxTemp = 0;
    profileName = NULL;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void MainDisplay::DrawPixel(uint32_t x, uint32_t y, uint8_t data)
{

}

void MainDisplay::DrawText(uint16_t x, uint16_t y, const char* str, uint16_t len, uint8_t fontSize)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << str;

    pos.X = 0; pos.Y = 20;
    SetConsoleCursorPosition(hConsole, pos);
}

void MainDisplay::DrawNumber(uint16_t x, uint16_t y, int32_t number, uint8_t fontSize)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << number;

    pos.X = 0; pos.Y = 20;
    SetConsoleCursorPosition(hConsole, pos);
}
    
void MainDisplay::DrawNumber(uint16_t x, uint16_t y, float number, uint8_t fontSize)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << number;

    pos.X = 0; pos.Y = 20;
    SetConsoleCursorPosition(hConsole, pos);
}

void MainDisplay::Clear()
{
    system("cls");
}

void MainDisplay::FillRectangle(uint16_t xTop, uint16_t yTop, uint16_t xBot, uint16_t yBot, uint8_t color)
{
    if (xBot < xTop) return;
    uint8_t count = (xBot - xTop) > 20 ? 20 : xBot - xTop;
    COORD pos = { (SHORT)xTop, (SHORT)yTop };
    SetConsoleCursorPosition(hConsole, pos);
    for (uint16_t i = 0; i < count; i++) std::cout << " ";
}

void MainDisplay::DrawRectangle(uint16_t xleft, uint16_t yleft, uint16_t xRight, uint16_t yRight, uint8_t color)
{

}    

void MainDisplay::Update()
{
    //std::cout << "\n";
}





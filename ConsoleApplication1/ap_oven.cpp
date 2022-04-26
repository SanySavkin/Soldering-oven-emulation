#include "MVP/Common/Model/oven_processor.h"
#include "Regulator/pid_regulator.h"
#include "ap_time_stamp.h"
#include "MVP/Common/Model/profiles.h"
#include "ap_oven.h"

#include "Windows.h"
#include <iostream>

extern Oven oven;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
extern Pid pid;

OvenControl::OvenControl()
{

}

uint32_t OvenControl::GetMs()
{
	return TimeStamp::GetMillis();
}

int32_t OvenControl::GetTemp()
{
	static int32_t temp = 0;
	temp = oven.GetSetTemp() > temp ? temp + 1 : temp - 1;
	temp += (10 * pid.GetCv()) / 1000;
	return temp;
}

void OvenControl::SetOutput(int32_t val)
{
	COORD pos = { (SHORT)0, (SHORT)18 };
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << "        ";
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << val;
}


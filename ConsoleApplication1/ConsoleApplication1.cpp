// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#pragma comment(lib, "winmm.lib")

#include <iostream>



#include "Main/Contracts/imain_view.h"
#include "buttons.h"
#include "Main/main_presenter.h"
#include "Activity/activity_manager.h"
#include "Activity/main_activity.h"
#include "Activity/proceess_activity.h"
#include "Process/process_presenter.h"
#include "Process/Contracts/iprocess_model.h"
#include "ap_console_display.h"
#include "oven_activities_manager.h"

#include <Windows.h>
#include <thread>
#include <chrono>

#include "ap_buttons.h"
#include "ap_time_stamp.h"
#include "ap_storage.h"
#include "ap_oven.h"


static void UpdateView();


RamStorage stor;
OvenControl ovProc;
Profiles prof(&stor);
Oven oven(&ovProc, &prof);

MainDisplay display;

const IButtons btnDrv = { KeyBoard::IsPressed };
Buttons buttons(TimeStamp::GetMillis, &btnDrv);

MainActivity mainAct(&display, &buttons);
ProcessActivity procAct(&display, &buttons);

MainPresenter mainPres(&oven, &mainAct);
ProcessPresenter procPres(&oven, &procAct);

Pid pid(6, 2, 0.9, 200);

int main()
{
    TimeStamp::Init();
    oven.SetPid(&pid);
    prof.Read();
    ActManager::StartActivity(ACTIVITY_MAIN);

    while (1)
    {
        buttons.Process();
        oven.Process();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        UpdateView();
    }
}


static void UpdateView()
{
    static uint32_t prevTime = 0;
    if (TimeStamp::GetMillis() - prevTime < 200) return;
    prevTime = TimeStamp::GetMillis();

    ActManager::Update();
    display.Update();
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

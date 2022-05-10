// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#pragma comment(lib, "winmm.lib")

#include <iostream>

#include "buttons.h"
#include "Activity/activity_manager.h"
#include "Activity/main_activity.h"
#include "Activity/proceess_activity.h"
#include "Activity/profiles_list_activity.h"
#include "Activity/profiles_info_activity.h"
#include "Activity/error_activity.h"
#include "Activity/wifi_activity.h"
#include "Activity/settings_activity.h"
#include "Activity/pid_activity.h"
#include "Activity/profile_edit_activity.h"
#include "Activity/fw_version_activity.h"

#include "Contracts/iprocess_model.h"
#include "ap_console_display.h"
#include "oven_activities_manager.h"
#include "Models/wifi_model.h"
#include "Models/pid_model.h"

#include <Windows.h>
#include <thread>
#include <chrono>

#include "ap_buttons.h"
#include "ap_time_stamp.h"
#include "ap_storage.h"
#include "ap_oven.h"
#include "win_sound.h"


static void UpdateView();


RamStorage stor;
OvenControl ovProc;
Profiles prof(&stor);
WinSound wSnd;

PidModel pidModel(&stor);
Oven oven(&ovProc, &prof, &pidModel);
WifiModel wifiModel(&stor);


MainDisplay display;

const IButtons btnDrv = { KeyBoard::IsPressed };
Buttons buttons(TimeStamp::GetMillis, &btnDrv);

MainActivity mainAct(&oven, &display, &buttons);
SettingsActivity setAct(&display, &buttons);
ProfilesListActivity profListAct(&prof, &display, &buttons);
ProfilesInfoActivity profInfoAct(&prof, &display, &buttons);
ProfilesEditActivity profEditAct(&prof, &display, &buttons, &wSnd);
ProcessActivity procAct(&oven, &display, &buttons);
PidActivity pidAct(&pidModel, &display, &buttons);
WifiActivity wifiAct(&wifiModel, &display, &buttons);
FwVersionActivity fwVersAct(&display, &buttons);
ErrorActivity errorAct(&display, &buttons, &wSnd);

uint32_t debugCount = 0;
int main()
{
    TimeStamp::Init();
    prof.Read();
    wifiModel.Read();
    pidModel.Read();
    ActivityManager::StartActivity(ActivityManager::ACTIVITY_MAIN, NULL);

    while (1)
    {
        debugCount++;

        buttons.Process();
        oven.Process();
        UpdateView();
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
    }
}


static void UpdateView()
{
    static uint32_t prevTime = 0;
    if (TimeStamp::GetMillis() - prevTime < 500) return;
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

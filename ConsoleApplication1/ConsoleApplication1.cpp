// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#pragma comment(lib, "winmm.lib")

#include <iostream>



#include "Main/Contracts/imain_view.h"
#include "buttons.h"

#include "Main/main_presenter.h"
#include "Error/error_presenter.h"
#include "ProfilesList/profile_list_prsenter.h"
#include "ProfileInfo/profile_info_presenter.h"
#include "Process/process_presenter.h"
#include "Wifi/wifi_presenter.h"
#include "Settings/settings_presenter.h"
#include "Pid/pid_presenter.h"

#include "Activity/activity_manager.h"
#include "Activity/main_activity.h"
#include "Activity/proceess_activity.h"
#include "Activity/profiles_list_activity.h"
#include "Activity/profiles_info_activity.h"
#include "Activity/error_activity.h"
#include "Activity/wifi_activity.h"
#include "Activity/settings_activity.h"
#include "Activity/pid_activity.h"

#include "Process/Contracts/iprocess_model.h"
#include "ap_console_display.h"
#include "oven_activities_manager.h"
#include "Common/Model/wifi_model.h"
#include "Common//Model/pid_model.h"

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

PidModel pidModel(&stor);
Oven oven(&ovProc, &prof, &pidModel);
WifiModel wifiModel(&stor);


MainDisplay display;

const IButtons btnDrv = { KeyBoard::IsPressed };
Buttons buttons(TimeStamp::GetMillis, &btnDrv);

MainActivity mainAct(&display, &buttons);
ProcessActivity procAct(&display, &buttons);
ProfilesListActivity profListAct(&display, &buttons);
ProfilesInfoActivity profInfoAct(&display, &buttons);
ErrorActivity errorAct(&display, &buttons);
WifiActivity wifiAct(&display, &buttons);
SettingsActivity setAct(&display, &buttons);
PidActivity pidAct(&display, &buttons);

MainPresenter mainPres(&oven, &mainAct);
ProcessPresenter procPres(&oven, &procAct);
ProfilesListPresenter profListPres(&prof, &profListAct);
ProfilesInfoPresenter profInfoPres(&prof, &profInfoAct);
ErrorPresenter errorPres(&oven, &errorAct);
WifiPresenter wifiPres(&wifiModel, &wifiAct);
SettingsPresenter setPres(&setAct);
PidPresenter pidPres(&pidModel, &pidAct);


uint32_t debugCount = 0;
int main()
{
    TimeStamp::Init();
    prof.Read();
    wifiModel.Read();
    pidModel.Read();
    prof.SetProfile(2);
    ActManager::StartActivity(ACTIVITY_MAIN);

    while (1)
    {
        debugCount++;
        buttons.Process();
        oven.Process();
        UpdateView();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
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

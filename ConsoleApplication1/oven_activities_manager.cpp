#include "oven_activities_manager.h"
#include "Activity/main_activity.h"
#include "Activity/proceess_activity.h"
#include "Activity/profiles_list_activity.h"
#include "Activity/profiles_info_activity.h"
#include "Activity/error_activity.h"
#include "Activity/wifi_activity.h"
#include "Activity/settings_activity.h"
#include "Activity/pid_activity.h"

#include "Main/main_presenter.h"
#include "Process/process_presenter.h"
#include "ProfilesList/profile_list_prsenter.h"
#include "ProfileInfo/profile_info_presenter.h"
#include "Error/error_presenter.h"
#include "Wifi/wifi_presenter.h"
#include "Settings/settings_presenter.h"
#include "Pid/pid_presenter.h"


extern MainActivity mainAct;
extern ProcessActivity procAct;
extern ProfilesListActivity profListAct;
extern ProfilesInfoActivity profInfoAct;
extern ErrorActivity errorAct;
extern WifiActivity wifiAct;
extern SettingsActivity setAct;
extern PidActivity pidAct;

extern MainPresenter mainPres;
extern ProcessPresenter procPres;
extern ProfilesListPresenter profListPres;
extern ProfilesInfoPresenter profInfoPres;
extern ErrorPresenter errorPres;
extern WifiPresenter wifiPres;
extern SettingsPresenter setPres;
extern PidPresenter pidPres;


void ActManager::StartActivity(ActivityIdEnum id)
{
	switch (id)
	{
	case ACTIVITY_START:

		break;
	case ACTIVITY_MAIN:
		mainAct.Subscribe(&mainPres);
		ActivityManager::StartActivity(&mainAct);
		break;
	case ACTIVITY_PROCESS:
		procAct.Subscribe(&procPres);
		ActivityManager::StartActivity(&procAct);
		break;
	case ACTIVITY_PROFILES_LIST:
		profListAct.Subscribe(&profListPres);
		ActivityManager::StartActivity(&profListAct);
		break;
	case ACTIVITY_PROFILE_INFO:
		profInfoAct.Subscribe(&profInfoPres);
		ActivityManager::StartActivity(&profInfoAct);
		break;
	case ACTIVITY_DIALOG:
		break;
	case ACTIVITY_ERROR:
		errorAct.Subscribe(&errorPres);
		ActivityManager::StartActivity(&errorAct);
		break;
	case ACTIVITY_WIFI:
		wifiAct.Subscribe(&wifiPres);
		ActivityManager::StartActivity(&wifiAct);
		break;
	case ACTIVITY_SETTINGS:
		setAct.Subscribe(&setPres);
		ActivityManager::StartActivity(&setAct);
		break;
	case ACTIVITY_PID:
		pidAct.Subscribe(&pidPres);
		ActivityManager::StartActivity(&pidAct);
		break;
	/*case ACTIVITY_FW_VERSION:
		wifiAct.Subscribe(&wifiPres);
		ActivityManager::StartActivity(&wifiAct);
		break;*/
	default:
		break;
	}
}

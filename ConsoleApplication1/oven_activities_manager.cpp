#include "oven_activities_manager.h"
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


extern MainActivity mainAct;
extern ProcessActivity procAct;
extern ProfilesListActivity profListAct;
extern ProfilesInfoActivity profInfoAct;
extern ErrorActivity errorAct;
extern WifiActivity wifiAct;
extern SettingsActivity setAct;
extern PidActivity pidAct;
extern ProfilesEditActivity profEditAct;
extern FwVersionActivity fwVersAct;


void ActManager::StartActivity(ActivityIdEnum id)
{
	switch (id)
	{
	case ACTIVITY_START:

		break;
	case ACTIVITY_MAIN:
		ActivityManager::StartActivity(&mainAct);
		break;
	case ACTIVITY_PROCESS:
		ActivityManager::StartActivity(&procAct);
		break;
	case ACTIVITY_PROFILES_LIST:
		ActivityManager::StartActivity(&profListAct);
		break;
	case ACTIVITY_PROFILE_INFO:
		ActivityManager::StartActivity(&profInfoAct);
		break;
	case ACTIVITY_PROFILE_EDIT:
		ActivityManager::StartActivity(&profEditAct);
		break;
	case ACTIVITY_DIALOG:
		break;
	case ACTIVITY_ERROR:
		ActivityManager::StartActivity(&errorAct);
		break;
	case ACTIVITY_WIFI:
		ActivityManager::StartActivity(&wifiAct);
		break;
	case ACTIVITY_SETTINGS:
		ActivityManager::StartActivity(&setAct);
		break;
	case ACTIVITY_PID:
		ActivityManager::StartActivity(&pidAct);
		break;
	case ACTIVITY_FW_VERSION:
		ActivityManager::StartActivity(&fwVersAct);
		break;
	default:
		break;
	}
}

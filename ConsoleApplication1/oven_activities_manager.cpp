#include "oven_activities_manager.h"
#include "Activity/main_activity.h"
#include "Activity/proceess_activity.h"

#include "Main/main_presenter.h"
#include "Process/process_presenter.h"


extern MainActivity mainAct;
extern ProcessActivity procAct;

extern MainPresenter mainPres;
extern ProcessPresenter procPres;


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
		break;
	case ACTIVITY_PROFILE_INFO:
		break;
	case ACTIVITY_DIALOG:
		break;
	default:
		break;
	}
}

#ifndef OVEN_ACTIVITY_MANAGER_H
#define OVEN_ACTIVITY_MANAGER_H


#include "stdint.h"
#include "string.h"
#include "Activity/activity_manager.h"


typedef enum
{
    ACTIVITY_START,
    ACTIVITY_MAIN,
    ACTIVITY_PROCESS,
    ACTIVITY_PROFILES_LIST,
    ACTIVITY_PROFILE_INFO,
    ACTIVITY_DIALOG
}ActivityIdEnum;


class ActManager : public ActivityManager
{
private:
    ActManager();
public:
    static void StartActivity(ActivityIdEnum);
};


#endif //OVEN_ACTIVITY_MANAGER_H


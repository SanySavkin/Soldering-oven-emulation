#ifndef PROFILES_LIST_ACTIVITY_H
#define PROFILES_LIST_ACTIVITY_H


#include "stdint.h"
#include "string.h"
#include "activity.h"
#include "ProfilesList/Contract/iporifile_list_view.h"
#include "idisplay.h"
#include "ibuttons.h"



class ProfilesListActivity : public Activity, public IProfileListView, public IButtonEvents
{
private:
    ProfilesListActivity();
    IProfileListViewEvents* ev;
    IDisplay* dsp;
    IButtonsSubscriber* btnSbscriber;
public:
    ProfilesListActivity(IDisplay*, IButtonsSubscriber*);
    ProfilesListActivity(IProfileListViewEvents*, IDisplay*, IButtonsSubscriber*);

    void OnCreate() override;
    void OnDestroy() override;
    void OnUpdate() override;

    void Show(uint8_t curIndx) override;
    void Subscribe(IProfileListViewEvents*) override;
    void Unsubscribe(IProfileListViewEvents*) override;

    //button event handlers
    void OnPressed(uint32_t indx) override;
    void OnLongPressed(uint32_t indx) override;
    void OnReleased(uint32_t indx) override;

};


#endif //PROFILES_LIST_ACTIVITY_H
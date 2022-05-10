#ifndef WIN_SOUND_H
#define WIN_SOUND_H


#include "stdint.h"
#include "string.h"
#include "Contracts/ievent_indication.h"




class WinSound : public IEventIndication
{
public:
    void SoundPlay(int32_t id) override;
    void StopSound(int32_t id) override;
    void Light(int32_t id, bool isOn, uint32_t durationMs) override;
 };



#endif // WIN_SOUND_H



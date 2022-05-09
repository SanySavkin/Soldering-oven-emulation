#ifndef WIN_SOUND_H
#define WIN_SOUND_H


#include "stdint.h"
#include "string.h"
#include "Common/Contracts/isound.h"


class WinSound : public ISound
{
public:
	void PlaySnd() override;
};

#endif // WIN_SOUND_H



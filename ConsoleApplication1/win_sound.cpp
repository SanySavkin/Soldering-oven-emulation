#pragma comment(lib, "winmm.lib")

#include "Windows.h"
#include "win_sound.h"



void WinSound::SoundPlay(int32_t id)
{
	switch (id)
	{
	case 0:
		PlaySoundA((LPCSTR)"C:/Users/Sany/source/repos/ConsoleApplication1/ConsoleApplication1/Beep_2000_300.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 1:
		PlaySoundA((LPCSTR)"C:/Users/Sany/source/repos/ConsoleApplication1/ConsoleApplication1/Beep_300_200.wav", NULL, SND_FILENAME | SND_ASYNC);
		break;
	default:
		break;
	}
	
}

void WinSound::StopSound(int32_t id)
{

}

void WinSound::Light(int32_t id, bool isOn, uint32_t durationMs)
{

}

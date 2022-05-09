#pragma comment(lib, "winmm.lib")

#include "win_sound.h"
#include "Windows.h"


void WinSound::PlaySnd()
{
	PlaySoundA((LPCSTR)"C:/Users/Sany/source/repos/ConsoleApplication1/ConsoleApplication1/Beep_2000_300.wav", NULL, SND_FILENAME | SND_ASYNC);
}

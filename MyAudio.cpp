#include "MyAudio.h"
#include "Novice.h"
void stopAudio(int AudioHandle)
{
	Novice::StopAudio(AudioHandle);
}
void playAudio(int& Audio, int& AudioHandle) {
	if (Novice::IsPlayingAudio(Audio) == 0 || Audio == -1) {
		Audio = Novice::PlayAudio(AudioHandle, false, 0.5f);
	}
}
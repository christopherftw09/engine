//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Sound
//

#include <iostream>
#include "Sound.h"

using namespace std;

Sound::Sound(const char* file)
{
	gMusic = Mix_LoadMUS(file);
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(gMusic, 0);
	}
}

Sound::Sound(const char* file, int loop)
{
	gSound = Mix_LoadWAV(file);
	channel = Mix_PlayChannel(-1, gSound, loop);

	if (channel) {
		printf("Mix_PlayChannel: %s\n", Mix_GetError());
	}
}

Sound::~Sound()
{
	Mix_FreeChunk(gSound); // free the sound effects
	gSound = nullptr;
	
	if (Mix_PlayingMusic() == 1) { Mix_HaltMusic(); Mix_FreeMusic(gMusic); }
	Mix_FreeMusic(gMusic); // free the music
	gMusic = nullptr;
}

void Sound::SetVolume(int volume)
{
	if (Mix_PlayingMusic())
	{
		Mix_Volume(channel, volume);
	}
}

int Sound::GetVolume()
{
	return ((128 * 100) / Mix_Volume(channel, -1));
}
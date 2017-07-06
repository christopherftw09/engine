//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: SoundManager (Header)
//

#include <SDL_mixer.h>
#include <iostream>
#include <list>

#include "Sound.h"

using namespace std;

class SoundManager
{
	private:
		list<Sound*> mSound;

	public:
		SoundManager();
		~SoundManager();

		int Play();
};
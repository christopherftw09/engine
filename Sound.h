//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Sound (Header)
//

#include <SDL_mixer.h>

class Sound
{
	private:
		Mix_Music* gMusic = nullptr; // A variable the music played will use.
		Mix_Chunk* gSound = nullptr; // A vairable the sound effects played will use.

		int channel = NULL; // channel the sound effect is played on.

	public:
		Sound(const char* file);
		Sound(const char* file, int loop);
		~Sound();

		void SetVolume(int volume);
		int GetVolume();
};
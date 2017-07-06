//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Settings (Header)
//

#pragma once

class Settings
{
	private:
		static Settings* mInstance;

		Settings();

	public:
		static Settings* Instance();

		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		float FOV; // Field of View.
};
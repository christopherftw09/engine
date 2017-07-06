//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Settings (Header)
//

#include "Settings.h"

Settings::Settings()
{
	SCREEN_WIDTH = 1440;
	SCREEN_HEIGHT = 900;
	FOV = 60;
}

Settings* Settings::Instance()
{
	if (!mInstance) {
		mInstance = new Settings;
	}
	return mInstance;
}
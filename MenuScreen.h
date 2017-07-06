//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Menu Scene (Header)
//

#pragma once
#include "Scene.h"

class MenuScene: public Scene
{
public:
	MenuScene();
	~MenuScene();

	void Render();
	bool Update(float deltaTime, SDL_Event e);

private:
	bool show_main_menu = true;
	bool show_settings_menu = false;

	// Settings
	int resolutions[2];

	int mode_selected;

	float fov_selected = 60.0f;

	float sound_volume;
};
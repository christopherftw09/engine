//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Menu Screen
//

#include "MenuScreen.h"
#include "SceneManager.h"
#include "Settings.h"

#include <list>

using namespace std;

extern SDL_Window* gWindow;

const char* mode_items[] = { "Fullscreen", "Windowed" };

MenuScene::MenuScene(): Scene()
{
	resolutions[0] = 1440;
	resolutions[1] = 900;

	mode_selected = 1;
	sound_volume = 100;
}

MenuScene::~MenuScene() {}

void MenuScene::Render()
{
	Scene::Render(); // calling scene's render function since it's dealing with the camera.

	bool show_another_window = true;
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;

	ImGui::SetNextWindowSize(ImVec2(440, 200));
	ImGui::SetNextWindowPosCenter();

	ImGui::Begin("Menu", &show_another_window, window_flags);
	// Main Menu
	if(show_main_menu)
	{
		ImGui::Text("Welcome!");
		ImGui::Spacing();

		if (ImGui::Button("Tech Demo"))
		{
			SceneManager::Instance()->SetScene(DEMO);
		}
		
		if (ImGui::Button("Settings"))
		{
			show_settings_menu = true;
			show_main_menu = false;
		}
	}

	// Settings Menu
	if(show_settings_menu)
	{
		ImGui::Text("Graphics Settings");
		ImGui::Spacing();

		ImGui::InputInt2("Resolution", resolutions);

		ImGui::Combo("Display Mode", &mode_selected, mode_items, _ARRAYSIZE(mode_items));

		ImGui::SliderFloat("Field of View", &Settings::Instance()->FOV, 60, 180, "%.0f");
		ImGui::Spacing();

		// Sound Settings
		ImGui::Text("Sound Settings");
		ImGui::Spacing();

		ImGui::SliderFloat("Game Volume", &sound_volume, 0, 100, "%.0f");

		ImGui::Spacing();

		if(ImGui::Button("Apply"))
		{
			switch(mode_selected)
			{
				Settings::Instance()->SCREEN_WIDTH = resolutions[0];
				Settings::Instance()->SCREEN_HEIGHT = resolutions[1];

				case 0: // Fullscreen
					glViewport(0, 0, resolutions[0], resolutions[1]);
					SDL_SetWindowSize(gWindow, resolutions[0], resolutions[1]);
					SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN);
				break;

				case 1: // Windowed
					glViewport(0, 0, resolutions[0], resolutions[1]);
					SDL_SetWindowSize(gWindow, resolutions[0], resolutions[1]);
					SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_OPENGL);
				break;
			}
			printf("Settings has been applied (Resolution: %d x %d, Screen Mode: %d, Field of View: %.0f, Sound: %.0f).\n", resolutions[0], resolutions[1], mode_selected, fov_selected, sound_volume);
		}
		ImGui::SameLine();
		if (ImGui::Button("Back")) { show_main_menu = true; show_settings_menu = false; }
		ImGui::SameLine();
	}
	ImGui::End();
}

bool MenuScene::Update(float deltaTime, SDL_Event e)
{
	Scene::Update(deltaTime, e);

	mCurrentTime += deltaTime;
	return true;
}
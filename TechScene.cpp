//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Tech Scene
//

#include "TechScene.h"
#include <SDL_mixer.h>

using namespace std;

Mix_Music* gMusic;

TechScene::TechScene(): Scene()
{
	mainCamera->SetPosition(Vector3(0.0f, -3.088f, -20.399f));
	mainCamera->SetRotation(Vector3(10.576794, 0.0, 0.0));

	skybox = new Skybox();
	ocean = new Ocean();
	bouy = new Cube();

	gMusic = Mix_LoadMUS("data/sounds/ocean.wav");
	if(Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(gMusic, 0);
	}
}

TechScene::~TechScene()
{
	if(Mix_PlayingMusic() == 1) { Mix_HaltMusic(); Mix_HaltMusic(); }

	delete ocean;
	delete bouy;
	delete skybox;
}

void TechScene::Render()
{
	Scene::Render(); // calling the parent to update the camera.
	skybox->Render();

	ocean->Render();
	bouy->Render();

	// Return Button.
	bool show_another_window = true;
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
	ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x/2 - 60), 8));
	ImGui::Begin("TechScene_BACK", &show_another_window, window_flags);
	if(ImGui::Button("Return to Menu")) { SceneManager::Instance()->SetScene(MENU); }
	ImGui::End();
}

bool TechScene::Update(float deltaTime, SDL_Event e)
{
	Scene::Update(deltaTime, e); // calling the parent to update the camera.
	
	ocean->Update(deltaTime, e);
	bouy->Update(deltaTime, e);

	mCurrentTime += deltaTime;
	return true;
}
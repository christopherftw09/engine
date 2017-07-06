//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Scene
//

#include "Scene.h"
#include <time.h>

#include "SoundManager.h"
SoundManager* soundManager;

Scene::Scene()
{
	soundManager = new SoundManager();
	printf("[Scene] Creating Scene.\n");
	mainCamera = new Camera();
	mainCamera->SetPosition(Vector3(0.0f, 0.0f, -10.0f)); // setting camera position.

	srand(time(NULL));
	printf("[Scene] Scene Created.\n");
}

Scene::~Scene()
{
	printf("[Scene] Deleting Scene.\n");
	delete mainCamera;
	printf("[Scene] Deleted Scene.\n\n");
}

void Scene::Render()
{
	mainCamera->Render();

	// FPS Counter
	bool show_another_window = true;
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
	ImGui::SetNextWindowPos(ImVec2(10, 10));
	ImGui::Begin("FPS", &show_another_window, window_flags);
	ImGui::Text("Average %.3f ms/frame (%.2f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();

#if DEBUG
	// Build Status
	ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x - 150), 8));
	ImGui::Begin("BuildType", &show_another_window, window_flags);
	ImGui::TextColored(ImColor(255, 0, 0, 255), "Development Build");
	ImGui::End();
#endif
}

bool Scene::Update(float deltaTime, SDL_Event e)
{
	mainCamera->Update(deltaTime, e);
	return true;
}
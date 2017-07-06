//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Scene Manager
//

#include "SceneManager.h"

SceneManager::SceneManager()
{
	mActive = new MenuScene();
}

Scene* SceneManager::GetScene()
{
	return mActive;
}

void SceneManager::SetScene(SCENES screen)
{
	if(mActive != nullptr) { delete mActive; }

	switch (screen)
	{
		case MENU:
			mActive = new MenuScene();
		break;

		case DEMO:
			mActive = new TechScene();
		break;
	}
}

SceneManager* SceneManager::Instance()
{
	if (!mInstance) {
		mInstance = new SceneManager;
	}
	return mInstance;
}

void SceneManager::Render()
{
	mActive->Render();
}

bool SceneManager::Update(float deltaTime, SDL_Event e)
{
	return mActive->Update(deltaTime, e);
}
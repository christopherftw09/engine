//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Scene Manager (Singleton) (Header)
//

#pragma once
#include "Scene.h"
#include <string>

#include "MenuScreen.h"
#include "TechScene.h"

using namespace std;

enum SCENES { MENU, DEMO };

class SceneManager
{
	Scene* mActive = nullptr;
	static SceneManager* mInstance;

	SceneManager();

	public:
		static SceneManager* Instance();
		
		void SetScene(SCENES screen);
		Scene* GetScene();
		
		void Render();
		bool Update(float deltaTime, SDL_Event e);
};
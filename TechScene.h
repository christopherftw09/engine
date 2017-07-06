//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Tech Scene (Header)
//

#pragma once
#include "Scene.h"
#include "SceneManager.h"

#include "Ocean.h"
#include "Cube.h"
#include "Skybox.h"

class TechScene: public Scene
{
	public:
		TechScene();
		~TechScene();

		void Render();
		bool Update(float deltaTime, SDL_Event e);
		
	private:
		Skybox* skybox;
		Object* ocean;
		Object* bouy;
};
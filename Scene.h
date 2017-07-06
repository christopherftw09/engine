//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Scene (Header)
//

#pragma once
#include <SDL.h>
#include <iostream>

#include <windows.h>

// OpenGL includes
#include <gl.h>
#include <gl\GLU.h>
#include <glut.h>

// ImGUI
#include <imgui.h>
#include <imgui_impl_sdl.h>

#include "Camera.h"
#include "Skybox.h"

class Scene
{
	public:
		Scene();
		virtual ~Scene();
		
		virtual void Render();
		virtual bool Update(float deltaTime, SDL_Event e);

	protected:
		Camera* mainCamera;
		Skybox* skybox;
		float mCurrentTime;
};
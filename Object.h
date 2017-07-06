//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Object (Header)
//

#pragma once
#include <SDL.h>

#include "Transform.h"
#include "Texture2D.h"

#include <windows.h>
#include <iostream>

#include "Shader.h"

//#include "glew.h"
// OpenGL includes
#include <gl.h>
#include <gl\GLU.h>
#include <glut.h>

class Object
{
	protected:
		Shader* shader;
		Texture2D* texture;

		Transform transform;
		Vector3 mPosition;
		Vector3 mRotation;
		Vector3 mScale;
		
		Object* mParent = nullptr;

	public:
		Object();
		Object(Object* parent);
		~Object();

		virtual void Render();
		virtual bool Update(float deltaTime, SDL_Event e);
		
		Vector3 GetPosition() { return mPosition; }
		void SetPosition(Vector3 position);

		Vector3 GetRotation() { return mRotation; }
		void SetRotation(Vector3 rotation);
};
//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Camera (Header)
//

#pragma once
#include "Object.h"
#include "Vector3.h"
#include "Color.h"

class Camera: public Object
{
	public:
		Camera();
		~Camera();

		void Render();
		bool Update(float deltaTime, SDL_Event e);

	private:
		bool updateCamera;
		Color backgroundColor;
		
		// Is the camera orthographic (true) or perspective (false)?
		bool orthographic;
		float orthographicSize;

		float m_fLeft;
		float m_fRight;
		float m_fTop;
		float m_fBottom;

		Vector3 m_Up;

		float mAngle;

		float aspect;
		float mfieldOfView;

		float nearClipPlane = 0.3f;
		float farClipPlane = 1000.0f;
};
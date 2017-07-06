//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Camera (Header)
//

#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

class Transform
{
	private:
		Vector3 mPosition;
		Vector3 mRotation;
		Vector3 mScale;

	public:
		Transform();

		Vector3 GetPosition();
		Vector3 GetRotation();
		Vector3 GetScale();

		void SetPosition(Vector3 newPosition);
		void SetRotation(Vector3 newRotation);
		void SetScale(Vector3 newScale);
};
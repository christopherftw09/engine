//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Quaternion (Header)
// quaternion

#pragma once

#include <cmath>
#include "Vector3.h"

struct Quaternion
{
	public:
		Vector3 vec; float w;
		Quaternion::Quaternion(float x, float y, float z, float w);
		
		static Quaternion identity;
		static Vector3 eulerAngles;

		static Quaternion Euler(float x, float y, float z);
		static Quaternion Euler(Vector3 euler);
};
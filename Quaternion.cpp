//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Quaternion
//

#include "Quaternion.h"

#pragma message("Quaternion.cpp - Needs to be implemented." )
Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->vec.x = x;
	this->vec.y = y;
	this->vec.z = z;
	this->w = w;
}

Quaternion Quaternion::Euler(Vector3 euler)
{
	return Quaternion(euler.x, euler.y, euler.z, 0);
}

Quaternion Quaternion::Euler(float x, float y, float z)
{
	return Quaternion(x, y, z, 0);
}
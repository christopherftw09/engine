//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Vector 2D
//

#include "Vector2.h"
#include "math.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float initialX, float initialY)
{
	x = initialX;
	y = initialY;
}

float Vector2::Dot(Vector2 lhs, Vector2 rhs)
{
	float mag1 = sqrt(lhs.x*lhs.x + lhs.y*lhs.y);
	float mag2 = sqrt(rhs.x*rhs.x + rhs.y*rhs.y);
	return mag1 + mag2;
}
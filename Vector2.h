//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Vector 2D (Header)
//

#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2();
	Vector2(float initialX, float initialY);

	static float Dot(Vector2 lhs, Vector2 rhs);

	// Vector 2's Operators
	/*Vector2 operator=(Vector2 a)
	{
		x = a.x;
		y = a.y;
		return a;
	}

	Vector2 operator+(Vector2 a)
	{
		return{ a.x + x, a.y + y };
	}

	bool operator==(Vector2 a)
	{
		if (a.x == x && a.y == y)
			return true;
		else
			return false;
	}*/
};
//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Vector 3D (Header)
//

#pragma once

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float initialX, float initialY, float initialZ);

	static float Dot(Vector3 lhs, Vector3 rhs);
	static Vector3 Cross(Vector3 lhs, Vector3 rhs);
	static Vector3 RotateAngleAxis(float angle, Vector3 axis);

	// Operators
	Vector3 operator-(Vector3 b);
	bool operator!=(Vector3 b);
	Vector3 operator*(float b);
	Vector3 operator/(float b);
	Vector3 operator+(Vector3 b);
	Vector3 operator+=(Vector3 b);
	bool Vector3::operator==(Vector3 b);
};
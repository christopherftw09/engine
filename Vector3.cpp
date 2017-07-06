//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Vector 3D
//

#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float initialX, float initialY, float initialZ)
{
	x = initialX;
	y = initialY;
	z = initialZ;
}

float Vector3::Dot(Vector3 lhs, Vector3 rhs)
{
	//
	return 0.0f;
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs)
{
	return Vector3(lhs.x, lhs.y, lhs.z);
}

Vector3 Vector3::RotateAngleAxis(float angle, Vector3 axis)
{
	return Vector3(axis.x*angle, axis.y*angle, axis.z*angle);
}

// Operators
Vector3 Vector3::operator-(Vector3 b)
{
	return Vector3(x - b.x, y - b.y, z - b.z);
}

bool Vector3::operator!=(Vector3 b)
{
	if (x == b.x && y == b.y && z == b.z) return 0;
	else return 1;
}

Vector3 Vector3::operator*(float b)
{
	return Vector3(x * b, y * b, z * b);
}

Vector3 Vector3::operator/(float b)
{
	return Vector3(x / b, y / b, z / b);
}

Vector3 Vector3::operator+(Vector3 b)
{
	return Vector3(x + b.x, y + b.y, z + b.z);
}

Vector3 Vector3::operator+=(Vector3 b)
{
	return Vector3(x += b.x, y += b.y, z += b.z);
}

bool Vector3::operator==(Vector3 b)
{
	if(x == b.x && y == b.y && z == b.z) return 1;
	else return 0;
}

#include "Transform.h"

Transform::Transform()
{
	mPosition = Vector3(0, 0, 0);
	mRotation = Vector3(0, 0, 0);
	mScale = Vector3(1, 1, 1);
}

Vector3 Transform::GetPosition() { return mPosition; }
void Transform::SetPosition(Vector3 newPosition) { mPosition = newPosition; }

Vector3 Transform::GetRotation() { return mRotation; }
void Transform::SetRotation(Vector3 newRotation) { mRotation = newRotation; }

Vector3 Transform::GetScale() { return mScale; }
void Transform::SetScale(Vector3 newScale) { mScale = newScale; }
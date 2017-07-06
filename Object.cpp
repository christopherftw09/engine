//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Object
//

#include "Object.h"

Object::Object()
{
	transform = Transform();
	mPosition = Vector3(0.0f, 0.0f, 0.0f);
	mRotation = Vector3(0.0f, 0.0f, 0.0f);
	mScale = Vector3(1.0f, 1.0f, 1.0f);
}

Object::Object(Object* parent)
{
	transform = Transform();
	mPosition = Vector3(0.0f, 0.0f, 0.0f);
	mRotation = Vector3(0.0f, 0.0f, 0.0f);
	mScale = Vector3(1.0f, 1.0f, 1.0f);

	mParent = parent;
}

Object::~Object() {}

void Object::Render()
{
	if (mParent != nullptr) { glTranslatef((mParent->GetPosition().x + mPosition.x), (mParent->GetPosition().y + mPosition.y), (mParent->GetPosition().z + mPosition.z)); } // setting object's position.
	else { glTranslatef(mPosition.x, mPosition.y, mPosition.z); } // setting object's position.

	glRotatef(mRotation.x, 1, 0, 0); // setting camera rotation.
	glRotatef(mRotation.y, 0, 1, 0);
	glRotatef(mRotation.z, 0, 0, 1);

	glScalef(mScale.x, mScale.y, mScale.z); // setting object scale.
}
bool Object::Update(float deltaTime, SDL_Event e) { return 1; }

void Object::SetPosition(Vector3 position)
{
	mPosition = position;
}

void Object::SetRotation(Vector3 rotation)
{
	mRotation = rotation;
}
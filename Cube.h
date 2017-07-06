//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Parent Object (Header)
//

#pragma once
#include "Object.h"

class Cube: public Object
{
	private:
		GLuint VertexArrayID; // This will identify our array id.
		GLuint vertexBuffer; // This will identify our vertex buffer.
		GLuint colorBuffer;

		Shader* shader;

		GLuint positionID;
		GLuint colorID;

	public:
		Cube();
		Cube(Object* parent);
		~Cube();

		virtual void Render();
		virtual bool Update(float deltaTime, SDL_Event e);
};
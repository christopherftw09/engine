//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Object (Cube)
//

#include "glew.h"
#include "Cube.h"

float waveWidth = 0.2;
float waveHeight = 2.5;
float waveTime = 0;

Cube::Cube(): Object()
{
	printf("[Cube] Creating Cube.\n");
	printf("[Cube] Cube Created.\n");
}

Cube::~Cube()
{
	
	printf("[Cube] Deleting Cube.\n");
	printf("[Cube] Cube Deleted.\n");
}

void Cube::Render()
{
	glPushMatrix();
		Object::Render();
		glBegin(GL_QUADS);
		// Top face (y = 1.0f) - Green
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);

		// Bottom face (y = -1.0f) - Orange
		//glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		// Front face  (z = 1.0f) - Red
		//glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		// Back face (z = -1.0f) - Yellow
		//glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);

		// Left face (x = -1.0f) - Blue
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		// Right face (x = 1.0f) - Magenta
		//glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glEnd();  // End of drawing color-cube
	glPopMatrix();
}

bool Cube::Update(float deltaTime, SDL_Event e)
{
	mPosition.y = (sin(waveWidth * mPosition.x + waveTime) * cos(waveWidth * mPosition.z + waveTime) * waveHeight);
	waveTime += deltaTime;
	return 1;
}
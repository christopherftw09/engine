//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Skybox
//

#include "Skybox.h"

#define GL_CLAMP_TO_EDGE 0x812F

Skybox::Skybox()
{
	texture[LEFT] = new Texture2D();
	texture[LEFT]->Load("data/skybox/default/left.png");

	texture[BACK] = new Texture2D();
	texture[BACK]->Load("data/skybox/default/back.png");

	texture[RIGHT] = new Texture2D();
	texture[RIGHT]->Load("data/skybox/default/right.png");

	texture[FRONT] = new Texture2D();
	texture[FRONT]->Load("data/skybox/default/front.png");

	texture[TOP] = new Texture2D();
	texture[TOP]->Load("data/skybox/default/top.png");

	texture[BOTTOM] = new Texture2D();
	texture[BOTTOM]->Load("data/skybox/default/bottom.png");
	
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/
}

Skybox::~Skybox()
{
	delete texture[LEFT];
	delete texture[BACK];
	delete texture[RIGHT];
	delete texture[FRONT];
	delete texture[TOP];
	delete texture[BOTTOM];
}

void Skybox::Render()
{
	//glPushMatrix();
		//glLoadIdentity();
		glBindTexture(GL_TEXTURE_2D, texture[FRONT]->GetID());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 1); glVertex3f(-512, -512, -512);
			glTexCoord2f(0, 1); glVertex3f(+512, -512, -512);
			glTexCoord2f(0, 0); glVertex3f(+512, +512, -512);
			glTexCoord2f(1, 0); glVertex3f(-512, +512, -512);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[BACK]->GetID());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 1); glVertex3f(+512, -512, +512);
			glTexCoord2f(0, 1); glVertex3f(-512, -512, +512);
			glTexCoord2f(0, 0); glVertex3f(-512, +512, +512);
			glTexCoord2f(1, 0); glVertex3f(+512, +512, +512);
		glEnd();
		
		/* Sides */
		glBindTexture(GL_TEXTURE_2D, texture[RIGHT]->GetID());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 1); glVertex3f(+512, -512, -512);
			glTexCoord2f(0, 1); glVertex3f(+512, -512, +512);
			glTexCoord2f(0, 0); glVertex3f(+512, +512, +512);
			glTexCoord2f(1, 0); glVertex3f(+512, +512, -512);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, texture[LEFT]->GetID());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 1); glVertex3f(-512, -512, +512);
			glTexCoord2f(0, 1); glVertex3f(-512, -512, -512);
			glTexCoord2f(0, 0); glVertex3f(-512, +512, -512);
			glTexCoord2f(1, 0); glVertex3f(-512, +512, +512);
		glEnd();

		/* Top and Bottom */
		glBindTexture(GL_TEXTURE_2D, texture[BOTTOM]->GetID());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 1); glVertex3f(+512, -512, -512);
			glTexCoord2f(0, 1); glVertex3f(-512, -512, -512);
			glTexCoord2f(0, 0); glVertex3f(-512, -512, +512);
			glTexCoord2f(1, 0); glVertex3f(+512, -512, +512);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[TOP]->GetID());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glBegin(GL_QUADS);
			glTexCoord2f(1, 1); glVertex3f(-512, +512, -512);
			glTexCoord2f(0, 1); glVertex3f(+512, +512, -512);
			glTexCoord2f(0, 0); glVertex3f(+512, +512, +512);
			glTexCoord2f(1, 0); glVertex3f(-512, +512, +512);
		glEnd();
	//glPopMatrix();
}
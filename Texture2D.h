//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Texture2D (Header)
//

#pragma once
#include "Texture.h"

#include <Windows.h>
#include <gl\GLU.h>
#include <iostream>
#include <string.h>
//#include <fstream>

class Texture2D: Texture
{
	private:
		GLuint _ID;
		int _width, _height;

	public:
		Texture2D();
		~Texture2D();

		bool Load(char* path);
		//bool Load(char* path, int width, int height);
		bool LoadBMP(const char * imagepath);

		GLuint GetID() const { return _ID; }
		//int GetWidth() const { return _width; }
		//int GetHeight() const { return _height; }
};
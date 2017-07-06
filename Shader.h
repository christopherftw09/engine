//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Shader (Header)
//

#pragma once
#include <windows.h>
#include <string>

#include <SDL_opengl.h>

// OpenGL includes
#include <gl.h>
#include <gl\GLU.h>
#include <glut.h>

using namespace std;

class Shader
{
	private:
		GLuint mProgram; // shader program id
		GLuint vs; // Vertex Shader id
		GLuint fs; // Fragment Shader id

		GLuint m_uniforms[3];

		string LoadShader(const string& fileName);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
		GLuint CreateShader(const string& text, unsigned int type);

	public:
		Shader(string fileName);
		~Shader();

		void Bind();
		GLuint GetID() { return mProgram; }
};
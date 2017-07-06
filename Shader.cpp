//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Shader
//

#include <glew.h>

#include "Shader.h"
#include <fstream>
#include <iostream>

Shader::Shader(string fileName)
{
	cout << "[Shader] Loading '" << fileName << "' shader." << endl;

	mProgram = glCreateProgram();
	
	vs = CreateShader(LoadShader("data/shaders/"+fileName+".vs"), GL_VERTEX_SHADER);
	fs = CreateShader(LoadShader("data/shaders/"+fileName+".fs"), GL_FRAGMENT_SHADER);

	glAttachShader(mProgram, vs);
	glAttachShader(mProgram, fs);

	glLinkProgram(mProgram);
	CheckShaderError(mProgram, GL_LINK_STATUS, true, "Error: Program linking failed: ");

	glValidateProgram(mProgram);
	CheckShaderError(mProgram, GL_VALIDATE_STATUS, true, "Error: Program linking failed: ");
}

Shader::~Shader()
{
	// detaching and then deleting the shaders.
	glDetachShader(mProgram, vs);
	glDetachShader(mProgram, fs);

	//glDeleteShader(vs);
	glDeleteShader(fs);

	// deleting the program.
	glDeleteProgram(mProgram);
}

void Shader::Bind()
{
	glUseProgram(mProgram);
}

GLuint Shader::CreateShader(const string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	
	if (shader == 0) { printf("Shader creation failed!\n"); }

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation failed: ");

	return shader;
}

string Shader::LoadShader(const std::string& fileName)
{
	ifstream file;
	file.open((fileName).c_str());

	string output;
	string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		cerr << "Unable to load shader: '"<< fileName << "'." << endl;
	}

	return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		printf("[Error] %s.\n", error);
	}
}
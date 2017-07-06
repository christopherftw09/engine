//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Ocean
//

#include "glew.h"
#include "Ocean.h"
#include "imgui.h"

#include "ObjLoader.h"
#include <vector>

Ocean::Ocean()
{
	shader = new Shader("ocean"); // calling the shader class to compile the shaders.

	waveWidth = 0.2;
	waveHeight = 2.5;
	
	waveWidthID = glGetUniformLocation(shader->GetID(), "waveWidth");
	waveHeightID = glGetUniformLocation(shader->GetID(), "waveHeight");
	GameTimeID = glGetUniformLocation(shader->GetID(), "waveTime");

	// Read our .obj file
	bool object = loadOBJ("data/waterPlane.obj", vertices, uvs, normals);

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Vertices
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vector3), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// UVs
	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(Vector2), &uvs[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Normals
	glGenBuffers(1, &normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Vector3), &normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Ocean::~Ocean()
{
	// Cleaning up the VBO, texture and shader
	glDeleteVertexArrays(1, &VertexArrayID);
	delete texture;
	delete shader;
}

void Ocean::Render()
{
	glUseProgram(shader->GetID());

	glUniform1f(waveWidthID, waveWidth);
	glUniform1f(waveHeightID, waveHeight);
	glUniform1f(GameTimeID, GameTime);

	glBindVertexArray(VertexArrayID);

	glPolygonMode(GL_FRONT, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size()); // drawing the triangles!
	glPolygonMode(GL_FRONT, GL_FILL);

	glBindVertexArray(0);
	glUseProgram(0);

	bool show_another_window = true;
	ImGui::SetNextWindowSize(ImVec2(400, 100));
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
	ImGui::Begin("Wave Settings", &show_another_window, window_flags);
	ImGui::SliderFloat("Wave Width", &waveWidth, 0.0f, 0.2f);
	ImGui::End();
}

bool Ocean::Update(float deltaTime, SDL_Event e)
{
	Object::Update(deltaTime, e);

	// Updating wave variable
	GameTime += deltaTime;
	return 1;
}
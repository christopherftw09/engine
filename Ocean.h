//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Parent Object (Header)
//

#pragma once
#include "Object.h"
#include <vector>
#include <cmath>

#define OCEAN_SIZE	650
#define WATER_HEIGHT	2.0f
#define MAX_HEIGHT		30.0f
#define SCALE_FACTOR    8.5f

class Ocean: public Object
{
	private:
		GLuint VertexArrayID;
		GLuint vertexBuffer;
		GLuint uvBuffer;
		GLuint normalBuffer;

		std::vector<Vector3> vertices;
		std::vector<Vector2> uvs;
		std::vector<Vector3> normals;

		GLfloat waveWidth, waveHeight, GameTime;
		GLint waveWidthID, waveHeightID, GameTimeID;
		GLuint TextureID;

		GLuint LightID, MatrixID, ModelMatrixID, ViewMatrixID;

	public:
		Ocean();
		~Ocean();

		virtual void Render();
		virtual bool Update(float deltaTime, SDL_Event e);
};
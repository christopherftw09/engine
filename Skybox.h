//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Skybox (Header)
//

#pragma once
#include "Texture2D.h"

enum SKYBOX_TEXTURE { FRONT, RIGHT, LEFT, BACK, TOP, BOTTOM };

class Skybox
{
	public:
		Skybox();
		~Skybox();
		
		void Render();
		bool Update();

	private:
		Texture2D* texture[6];
};
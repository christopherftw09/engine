//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Color
//

#include "Color.h"

Color::Color()
{
	r = 0, g = 0, b = 0, a = 0;
}

Color::Color(float red, float green, float blue, float alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}
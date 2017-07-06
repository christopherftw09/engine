/*
 * Ocean Vertex Shader
 * Created by Chris Mooney.
*/

#version 120

uniform float waveTime;
uniform float waveWidth;
uniform float waveHeight;

void main()
{	
	vec4 position = gl_Vertex;
	
	position.y = sin(waveWidth * position.x + waveTime) * cos(waveWidth * position.z + waveTime) * waveHeight;
	gl_Position = gl_ModelViewProjectionMatrix * position;
}
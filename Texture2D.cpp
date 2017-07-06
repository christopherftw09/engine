//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Texture2D
//

#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define GL_CLAMP_TO_EDGE 0x812F

using namespace std;

Texture2D::Texture2D(): Texture() { glEnable(GL_TEXTURE_2D); }
Texture2D::~Texture2D() { glDeleteTextures(1, &_ID); }

bool Texture2D::Load(char* path)
{
	int numComponents, width, height;
	unsigned char* tempTextureData;

	tempTextureData = stbi_load(path, &width, &height, &numComponents, 4);

	if (tempTextureData == NULL) { printf("Failed to load texture ('%s')\n", path); return 0; }

	glGenTextures(1, &_ID); // get next texture id.
	glBindTexture(GL_TEXTURE_2D, _ID); // bind the texture to the id.

	// Texture Parameters
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);*/

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tempTextureData);

	stbi_image_free(tempTextureData);
	return 1;
}

/*bool Texture2D::Load(char* path, int width, int height)
{

	char* tempTextureData; int fileSize; ifstream inFile;
	_width = width; _height = height;
	inFile.open(path, ios::binary);

	if(!inFile.good())
	{
		cerr << "[Texture 2D] Can't open texture file. " << path << endl;
		return false;
	}

	inFile.seekg(0, ios::end); // seek to end of file.
	fileSize = (int)inFile.tellg(); // getting current position in file - the end, this gives us total file size.
	tempTextureData = new char[fileSize]; // create new array to store the data.
	inFile.seekg(0, ios::beg); // seeking back to the beginning of the file.
	inFile.read(tempTextureData, fileSize); // read in all the data in one go.
	inFile.close();

	cout << "[Texture 2D] " << path << " loaded. " << endl;

	glGenTextures(1, &_ID); // get next texture id.
	glBindTexture(GL_TEXTURE_2D, _ID); // bind the texture to the id.
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	delete[] tempTextureData; // clearing up the data.
	return 1;
}

bool Texture2D::LoadBMP(const char * imagepath)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	// Open the file
	FILE * file = fopen(imagepath, "rb");
	if (!file){ printf("Image could not be opened\n"); return 0; }

	if (fread(header, 1, 54, file) != 54){ // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return false;
	}

	if (header[0] != 'B' || header[1] != 'M'){
		printf("Not a correct BMP file\n");
		return 0;
	}

	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	glGenTextures(1, &_ID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, _ID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	return 1;
}*/
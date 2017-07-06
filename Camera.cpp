//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Camera
//

#include "Camera.h"
#include "Settings.h"

using namespace std;

extern SDL_Window* gWindow;

float MovementSpeed = 3.2f;
float RotationSpeed = 10.4f;

float mouseSpeed = 0.005f;

float horizontalAngle = 0.0f;
float verticalAngle = 0.0f;

bool MoveUp, MoveDown, MoveForward, MoveBackward, MoveLeft, MoveRight;
bool RotateForward, RotateBackward, RotateLeft, RotateRight, MouseMovement;

Camera::Camera(): Object()
{
	// Setting Camera Vairables.
	backgroundColor = Color(0, 0, 0, 255);

	updateCamera = true;

	orthographicSize = 5.0f;

	aspect = ((float)Settings::Instance()->SCREEN_WIDTH / (float)Settings::Instance()->SCREEN_HEIGHT);
	mfieldOfView = Settings::Instance()->FOV;

	nearClipPlane = 0.3f;
	farClipPlane = 1000.0f;

	m_Up = Vector3(0.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST); // Removing any surfaces hiding away from the camera.
	glEnable(GL_CULL_FACE);	// stopping the calculation of any inside faces.
}

Camera::~Camera() {}

void Camera::Render()
{
	// Clearing the screen before attepting to render the screen again.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	
	if(updateCamera)
	{
		glViewport(0, 0, Settings::Instance()->SCREEN_WIDTH, Settings::Instance()->SCREEN_HEIGHT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if(orthographic)
		{
			glOrtho(-orthographicSize, orthographicSize, -orthographicSize, orthographicSize, nearClipPlane, farClipPlane);
		}
		else
		{
			gluPerspective(mfieldOfView, aspect, nearClipPlane, farClipPlane);
		}
		updateCamera = false;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Object::Render();
}

bool Camera::Update(float deltaTime, SDL_Event e)
{
	//printf("Position: %f %f %f\nRotation: %f %f %f\n", mPosition.x, mPosition.y, mPosition.z, mRotation.x, mRotation.y, mRotation.z);
	if(MoveUp) { mPosition.y += MovementSpeed*deltaTime; }
	if(MoveDown) { mPosition.y -= MovementSpeed*deltaTime; }
	if(MoveForward) { mPosition.z += MovementSpeed*deltaTime; }
	if(MoveBackward) { mPosition.z -= MovementSpeed*deltaTime; }
	if(MoveLeft) { mPosition.x += MovementSpeed*deltaTime; }
	if(MoveRight) { mPosition.x -= MovementSpeed*deltaTime; }

	if(RotateForward) { mRotation.x -= RotationSpeed*deltaTime; }
	if(RotateBackward) { mRotation.x += RotationSpeed*deltaTime; }
	if(RotateLeft) { mRotation.y += RotationSpeed*deltaTime; }
	if(RotateRight) { mRotation.y -= RotationSpeed*deltaTime; }

	if(MouseMovement)
	{
		int posx, posy; // Get mouse position
		SDL_GetMouseState(&posx, &posy);
		SDL_WarpMouseInWindow(gWindow, (Settings::Instance()->SCREEN_WIDTH / 2), (Settings::Instance()->SCREEN_HEIGHT/2)); // resetting the mouse position for the next frame.

		// Compute new orientation
		horizontalAngle += mouseSpeed * deltaTime * float(Settings::Instance()->SCREEN_WIDTH / 2 - posx);
		verticalAngle += mouseSpeed * deltaTime * float(Settings::Instance()->SCREEN_HEIGHT / 2 - posy);

		printf("%f, %f\n", horizontalAngle, verticalAngle);
		mRotation.x += verticalAngle;
		mRotation.y += horizontalAngle;
	}

	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) { MouseMovement = true; } else { MouseMovement = false; }

	// Keyboard Controls
	if(e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_w: MoveForward = true; break;
			case SDLK_s: MoveBackward = true; break;
			case SDLK_e: MoveUp = true; break;
			case SDLK_q: MoveDown = true; break;
			case SDLK_a: MoveLeft = true; break;
			case SDLK_d: MoveRight = true; break;
			case SDLK_UP: RotateForward = true; break;
			case SDLK_DOWN: RotateBackward = true; break;
			case SDLK_LEFT: RotateLeft = true; break;
			case SDLK_RIGHT: RotateRight = true; break;
		}
	}

	if(e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_w: MoveForward = false; break;
			case SDLK_s: MoveBackward = false; break;
			case SDLK_e: MoveUp = false; break;
			case SDLK_q: MoveDown = false; break;
			case SDLK_a: MoveLeft = false; break;
			case SDLK_d: MoveRight = false; break;
			case SDLK_UP: RotateForward = false; break;
			case SDLK_DOWN: RotateBackward = false; break;
			case SDLK_LEFT: RotateLeft = false; break;
			case SDLK_RIGHT: RotateRight = false; break;
		}
	}
	return 1;
}
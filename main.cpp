//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: Main
//

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

#include <imgui.h>
#include <imgui_impl_sdl.h>

#include "Settings.h" // screen settings - window width, height.
#include "SceneManager.h"
#include "SoundManager.h"

using namespace std;

// Global Variables
SDL_Window* gWindow = nullptr;
SDL_GLContext gGLContext = NULL;
Uint32 gOldTime;

// Local Variables.
Settings* Settings::mInstance = nullptr;
SceneManager* SceneManager::mInstance = nullptr;
//SoundManager* SoundManager::mInstance = nullptr;

// Local Function Prototypes
bool Initialize();
void Deinitialize();

void Render();
bool Update();

int main(int argc, char* args[])
{
	SetConsoleTitle("Debug Console");
	cout << "Debug Console Started.\n" << endl;

	if (Initialize()) // Initialising SDL and OpenGL.
	{
		bool running = true;
		gOldTime = SDL_GetTicks(); // setting the 'gOldTime' variable.

		do // The Game Loop.
		{
			Render();
			running = Update();
		}
		while(running);
	}

	// Closing the game window and then freeing up any used resources (see i'm recycling :D).
	Deinitialize();
	return 0;
}

bool Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		cout << "[Error] SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		// Attempt to set texture filtering to linear.
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cout << "*** Warning: Linear texture filtering not available. ***" << endl;
		}

		// Requesting OpenGL's 3.1 context. (3.2)
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		// Creating the game window.
		gWindow = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Settings::Instance()->SCREEN_WIDTH, Settings::Instance()->SCREEN_HEIGHT, SDL_WINDOW_OPENGL); // SDL_FULLSCREEN SDL_RESIZABLE

		// Did the window get created?
		if(gWindow == NULL)
		{
			cout << "We encountered a problem while creating game window was not created. (Error: " << SDL_GetError() << ")" << endl;
			return false;
		}

		gGLContext = SDL_GL_CreateContext(gWindow);

		// Did we setup the OpenGL context.
		if (gGLContext == NULL) { printf("We encountered a problem while creating the OpenGL context. (Error: %s).", SDL_GetError()); return false; }

		//Initializing GLEW
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();

		if (glewError != GLEW_OK) { printf("We encountered a problem while initializing GLEW! (Error: %s)\n", glewGetErrorString(glewError)); return false; }

		printf("*** You are using OpenGL version: %s. ***\n\n", glGetString(GL_VERSION));

		ImGui_ImplSdl_Init(gWindow);
	}
	return true;
}

void Deinitialize()
{
	ImGui_ImplSdl_Shutdown();

	// Destroying opengl's context.
	SDL_GL_DeleteContext(gGLContext);
	gGLContext = NULL;

	// Destroy the window.
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	// Quit SDL subsystems.
	SDL_Quit();
}

void Render()
{
	ImGui_ImplSdl_NewFrame(gWindow); // imgui stuff.

	SceneManager::Instance()->Render();
	
	ImGui::Render(); // render gui stuff.

	// Updating the OpenGL renderer.
	SDL_GL_SwapWindow(gWindow);
}

bool Update()
{
	// Getting and setting the new time.
	Uint32 newTime = SDL_GetTicks();

	// Event Handler.
	SDL_Event e;

	// Get the events.
	SDL_PollEvent(&e);

	ImGui_ImplSdl_ProcessEvent(&e); // processing the gui stuff.

	// Handle any upcoming events.
	switch (e.type)
	{
		case SDL_QUIT: // What happens if the user clicks the windowss (red) cross button.
			return false;
		break;

		default:
			SceneManager::Instance()->Update((float)(newTime - gOldTime) / 1000.0f, e);
		break;
	}

	// Set the current time to be the old time.
	gOldTime = newTime;
	return true;
}

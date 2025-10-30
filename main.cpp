#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Engine.h"

#pragma comment(lib, "SDL3") //x64 SDL3.lib



int SDL_main(int argc, char* argv[])
{

	GEngine->Init();
	GEngine->Run();
	GEngine->End();


	return 0;
}
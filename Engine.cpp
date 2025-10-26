#include "Engine.h"

FEngine::FEngine()
{
	KeyCode = 0;
}

FEngine::~FEngine()
{
}

void FEngine::Init()
{

}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}

}

void FEngine::End()
{

}

void FEngine::Input()
{
	KeyCode = _getch();
}

void FEngine::Tick()
{
}

void FEngine::Render()
{
}



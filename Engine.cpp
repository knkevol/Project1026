#include <SDL3/SDL_platform_defines.h>

#include "Engine.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "World.h"

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>



FEngine* FEngine::Instance = nullptr;

FEngine::FEngine() : MyEvent(SDL_Event())
{
	World = nullptr;
}

FEngine::~FEngine()
{
	delete World;
}

void FEngine::OpenLevel()
{
	//srand((unsigned int)time(nullptr));

	World = new UWorld();

	ifstream MapFile("Level101.map");
	if (MapFile.is_open())
	{
		char Buffer[1024] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 80)) // Y
		{
			string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X) // X
			{
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}
				AActor* NewActor = new AFloor();
				NewActor->SetActorLocation(FVector2D(X, Y));
				NewActor->SetShape(' ');
				World->SpawnActor(NewActor);


			}
			Y++;
		}
		MapFile.close();
		World->SortActor();
	}
}

void FEngine::Init()
{

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	MyWindow = SDL_CreateWindow("GameEngine", 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	OpenLevel();
	
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			switch (MyEvent.type)
			{
			case SDL_QUIT:
				bIsRunning = false;
				break;
			}
		}
		Input();
		Tick();
		Render();
	}

}

void FEngine::End()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

}

void FEngine::Input()
{
	KeyCode = _getch();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
	SDL_RenderClear(MyRenderer);

	GetWorld()->Render();

	SDL_RenderPresent(MyRenderer);
}



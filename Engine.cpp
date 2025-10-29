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

FEngine::FEngine()
{
	World = nullptr;
}

FEngine::~FEngine()
{
	delete World;
}

void FEngine::Init()
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
				else if (Line[X] == ' ')
				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(Line[X]);
					World->SpawnActor(NewActor);
				}

				

			}
			Y++;
		}
		//vector<AActor*>& AllActors = World->GetAllActors();
		//sort(AllActors.begin(), AllActors.end(), 
		//	[](AActor* A, AActor* B) {return A->GetZOder() < B->GetZOder(); });
		MapFile.close();
		World->SortActor();
	}
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
	bIsRunning = false;

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
	GetWorld()->Render();
}



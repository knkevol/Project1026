#include "Player.h"
#include "conio.h"
#include "Engine.h"
#include "World.h"
#include <vector>

APlayer::APlayer()
{
	ZOrder = 3;
	bIsCollision = true;

}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();
	FVector2D PreLocation(Location);

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if (KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
	}

	
	vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	
	bool bFlag = false;
 	for (auto Actor : AllActors)
	{
		if (CheckCollision(Actor) && this != Actor)
		{
			bFlag = true;

			break; //*
		}
	}

	if (bFlag)
	{
		Location = PreLocation;
	}
	
}

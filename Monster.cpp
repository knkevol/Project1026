#include "Monster.h"
#include "Engine.h"
#include "World.h"

AMonster::AMonster()
{
	ZOrder = 2;
	bIsCollision = true;
}

AMonster::~AMonster()
{

	
}

void AMonster::Tick()
{
	int KeyCode = rand() % 4;

	FVector2D PreLocation = Location;

	switch (KeyCode)
	{
	case 0:
		Location.Y++;
	case 1:
		Location.X--;
	case 2:
		Location.Y--;
	case 3:
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
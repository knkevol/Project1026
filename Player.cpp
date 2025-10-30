#include "Player.h"
#include "conio.h"
#include "Engine.h"
#include "World.h"
#include <vector>

#include "CollisionComponent.h"
#include "PaperFlipbookComponent.h"
#include "Actor.h"

APlayer::APlayer()
{
	Collision = new UCollisionComponent;
	Collision->SetCollision(true);
	Collision->SetOverlap(true);
	SetUpAttachment(Collision);

	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(3);
	SetUpAttachment(PaperFlipbook);

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
		for (auto Comp : Actor->GetAllComponents())
		{
			UCollisionComponent* CollisionComp = dynamic_cast<UCollisionComponent*>(Comp);
			if (Collision->CheckCollision(CollisionComp))
			{
				bFlag = true;

				break; //*
			}
		}
		
	}

	if (bFlag)
	{
		Location = PreLocation;
	}
	
}

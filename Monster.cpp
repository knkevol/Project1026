#include "Monster.h"
#include "Engine.h"
#include "World.h"

#include "CollisionComponent.h"
#include "PaperFlipbookComponent.h"
#include "Component.h"
#include "Actor.h"

AMonster::AMonster()
{
	Collision = new UCollisionComponent();
	Collision->SetCollision(true);
	Collision->SetOverlap(true);
	SetUpAttachment(Collision);

	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(2);
	PaperFlipbook->SetShape('M');
	PaperFlipbook->SetOwner(this);
	SetUpAttachment(PaperFlipbook);
}

AMonster::~AMonster()
{

	
}

void AMonster::Tick()
{
	int KeyCode = rand() % 4;

	FVector2D PreLocation(Location);

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
		for (auto Comp : Actor->GetAllComponents())
		{
			UCollisionComponent* CollisionComp = dynamic_cast<UCollisionComponent*>(Comp); //컴포넌트 중에 컬리전컴포넌트만
			if (CollisionComp)
			{
				if (Collision->CheckCollision(CollisionComp))
				{
					bFlag = true;
					break; //*
				}
			}
			
		}
		
	}

	if (bFlag)
	{
		Location = PreLocation;
	}

}
#include "GameMode.h"
#include "Engine.h"
#include "World.h"
#include "Player.h"

AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	AActor* Player = nullptr;

	vector<AActor*> AllActors;
	GEngine->GetWorld()->GetAllActors(AllActors);

	for (auto Actor : AllActors)
	{
		if (dynamic_cast<APlayer*>(Actor))
		{
			Player = dynamic_cast<APlayer*>(Actor);
			break;
		}
	}

}

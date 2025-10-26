#include "World.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

vector<AActor*> UWorld::GetAllActors(vector<AActor*>& InActors) const
{
    InActors = Actors;
    return InActors;
}

AActor* UWorld::SpawnActor(AActor* InSpawnActor)
{
    Actors.push_back(InSpawnActor);
    return InSpawnActor;
}

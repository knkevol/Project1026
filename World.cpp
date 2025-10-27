#include "World.h"
#include "Actor.h"

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

void UWorld::Tick()
{
    for (auto Actor : Actors)
    {
        Actor->Tick();
    }
}

void UWorld::Render()
{
    for (auto Actor : Actors)
    {
        Actor->Render();
    }
}
#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

vector<AActor*> UWorld::GetAllActors(vector<AActor*>& OutActors)
{
    OutActors = Actors;
    return OutActors;
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

void UWorld::SortActor()
{
    for (int i = 0; i < Actors.size(); ++i)
    {
        for (int j = 0; j < Actors.size(); ++j)
        {
            if (Actors[i]->GetZOder() < Actors[j]->GetZOder())
            {
                AActor* Temp = Actors[i];
                Actors[i] = Actors[j];
                Actors[j] = Temp;
            }
        }

    }
}

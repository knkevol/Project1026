#include "World.h"
#include "Actor.h"
#include "PaperFlipbookComponent.h"

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
        //Actor->Render();
        for (auto Comp : Actor->GetAllComponents())
        {
            USceneComponent* Scene = dynamic_cast<USceneComponent*>(Comp);
            if (Scene)
            {
                Scene->Render();
            }
        }
    }
}

void UWorld::SortActor()
{
    for (int i = 0; i < Actors.size(); ++i)
    {
        UPaperFlipbookComponent* PaperFlipbook1 = nullptr;
        for (auto Comp : Actors[i]->GetAllComponents())
        {
            PaperFlipbook1 = dynamic_cast<UPaperFlipbookComponent*>(Comp);
            if (PaperFlipbook1)
            {
                break;
            }


        }

        if (!PaperFlipbook1)
        {
            continue;
        }

        for (int j = 0; j < Actors.size(); ++j)
        {
            UPaperFlipbookComponent* PaperFlipbook2 = nullptr;
            for (auto Comp : Actors[j]->GetAllComponents())
            {
                PaperFlipbook2 = dynamic_cast<UPaperFlipbookComponent*>(Comp);
                if (PaperFlipbook2)
                {
                    break;
                }
            }

            if (!PaperFlipbook2)
            {
                continue;

            }
            if (PaperFlipbook1->GetZOder() < PaperFlipbook2->GetZOder())
            {
                AActor* Temp = Actors[i];
                Actors[i] = Actors[j];
                Actors[j] = Temp;
            }
        }

    }
}
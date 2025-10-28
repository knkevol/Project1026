#pragma once


#include "Engine.h"

#include <vector>

using namespace std;

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	vector<AActor*>& GetAllActors(/*vector<AActor*>& InActors*/);

	AActor* SpawnActor(AActor* InSpawnActor);

	virtual void Tick();
	virtual void Render();

	void SortActor();


protected:
	vector<AActor*> Actors;

};


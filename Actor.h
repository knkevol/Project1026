#pragma once
#include <iostream>
#include <vector>
#include "Vector.h"

class UComponent;
class UPaperFlipbookComponent;


using namespace std;

class AActor
{
public: 
	AActor();
	virtual ~AActor();

	virtual void Tick();
	//virtual void Render();

	__forceinline FVector2D GetActorLocation() const { return Location; }
	void SetActorLocation(FVector2D InVector)
	{
		Location.X = InVector.X;
		Location.Y = InVector.Y;
	}

protected:
	FVector2D Location;
	

//	Component
public:
	void SetUpAttachment(UComponent* InComp);
	vector<UComponent*> GetAllComponents() const { return Components; }

protected:
	vector<UComponent*> Components;
	UPaperFlipbookComponent* PaperFlipbook;
	
};
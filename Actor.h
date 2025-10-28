#pragma once
#include <iostream>
#include "Vector.h"


using namespace std;

class AActor
{
public: 
	AActor();
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	__forceinline FVector2D GetActorLocation() const { return Location; }
	void SetActorLocation(FVector2D InVector)
	{
		Location.X = InVector.X;
		Location.Y = InVector.Y;
	}

	__forceinline char GetShape() { return Shape; }
	void SetShape(char InShape)
	{
		Shape = InShape;
	}

	__forceinline char GetZOder() const { return ZOrder; }

	bool CheckCollision(AActor* Other);

protected:
	FVector2D Location;
	char Shape;
	int ZOrder;

public:
	bool bIsCollision = false;
	bool bIsOverlap = true;
};
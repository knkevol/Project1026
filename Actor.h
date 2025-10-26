#pragma once

#include "Vector.h"

using namespace std;

class AActor
{
public: 
	AActor();
	virtual ~AActor();

	__forceinline FVector2D GetLocation() { return Location; }

	__forceinline char GetShape() { return Shape; }
	char SetShape(char InShape)
	{
		Shape = InShape;
	}

protected:
	void Move();

public:

protected:
	FVector2D Location;
	char Shape;
};
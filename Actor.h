#pragma once

#include "Vector.h"

using namespace std;

class AActor
{
public: 
	AActor();
	virtual ~AActor();

protected:
	void Move();

public:

protected:
	FVector2D Location;
	char Shape;


};
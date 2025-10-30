#pragma once

class UPaperFlipbookComponent;

#include "Actor.h"

class AGoal : public AActor
{
public:
	AGoal();
	virtual ~AGoal();

// Component
protected:
	UPaperFlipbookComponent* PaperFlipbook;
};


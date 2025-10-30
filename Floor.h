#pragma once

#include "Actor.h"

class UPaperFlipbookComponent;

class AFloor : public AActor
{
public:
	AFloor();
	virtual ~AFloor();

protected:


// Component
protected:
	UPaperFlipbookComponent* PaperFlipbook;
};


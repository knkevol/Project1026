#pragma once

#include "Actor.h"

class UCollisionComponent;
class UPaperFlipbookComponent;

class AWall : public AActor
{
public:
	AWall();
	virtual ~AWall();


// Component
protected:
	UCollisionComponent* Collision;
	UPaperFlipbookComponent* PaperFlipbook;

	
};


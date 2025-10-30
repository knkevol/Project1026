#pragma once

#include "Actor.h"

class UCollisionComponent;
class UPaperFlipbookComponent;

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;


// Component
protected:
	UCollisionComponent* Collision;
	UPaperFlipbookComponent* PaperFlipbook;
};


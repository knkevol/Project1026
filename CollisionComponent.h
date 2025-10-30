#pragma once
#include "Component.h"

class AActor;

class UCollisionComponent : public UComponent
{
public: 
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void Tick() override;


	bool CheckCollision(const UCollisionComponent* InComp);

	__forceinline bool GetCollision() const { return bIsCollision; }
	bool SetCollision(bool InCollisionValue) 
	{
		return InCollisionValue;
	}

	__forceinline bool GetOverlap() const { return bIsOverlap; }
	bool SetOverlap(bool InOverlapValue)
	{
		return InOverlapValue;
	}

protected:
	bool bIsCollision = false;
	bool bIsOverlap = true;
};


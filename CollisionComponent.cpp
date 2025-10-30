#include "CollisionComponent.h"
#include "Actor.h"

UCollisionComponent::UCollisionComponent()
{
}

UCollisionComponent::~UCollisionComponent()
{
}

void UCollisionComponent::Tick()
{
}

bool UCollisionComponent::CheckCollision(const UCollisionComponent* InComp)
{
	if (InComp->bIsOverlap)
	{
		return false;
	}

	if (InComp->bIsCollision && bIsCollision
		&& (this != InComp) && (this->GetOwner()->GetActorLocation() == InComp->GetOwner()->GetActorLocation()))
	{
		
		return true;
	}
}

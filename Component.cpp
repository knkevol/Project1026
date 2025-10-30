#include "Component.h"

UComponent::UComponent()
{
	Owner = nullptr;
}

UComponent::~UComponent()
{
}

void UComponent::SetOwner(AActor* InOwner)
{
}

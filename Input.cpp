#include "Input.h"
#include "Engine.h"

int UInput::KeyCode = 0;

UInput::UInput()
{
}

UInput::~UInput()
{
}

void UInput::Tick()
{
	if (GEngine->GetMyEvent().key.down)
	{
		KeyCode = GEngine->GetMyEvent().key.key;
	}
	else
	{
		KeyCode = 0;
	}
}

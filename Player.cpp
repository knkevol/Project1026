#include "Player.h"
#include "conio.h"
#include "Engine.h"

APlayer::APlayer()
{
	ZOrder = 3;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetKeyCode();

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	else if (KeyCode == 's')
	{
		Location.Y++;
	}
	else if (KeyCode == 'a')
	{
		Location.X--;
	}
	else if (KeyCode == 'd')
	{
		Location.X++;
	}
}

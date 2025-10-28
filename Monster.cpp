#include "Monster.h"

AMonster::AMonster()
{
	ZOrder = 2;
}

AMonster::~AMonster()
{

	int KeyCode = rand() % 4;

	switch (KeyCode)
	{
	case 'w':
		Location.Y--;
		break;
	case 'a':
		Location.X--;
		break;
	case 's':
		Location.Y++;
		break;
	case 'd':
		Location.X++;
		break;
	}
}

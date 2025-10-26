#pragma once

struct FVector2D
{
	FVector2D(int InX, int InY) : X(0), Y(0) //Init
	{
		
	}

	virtual ~FVector2D()
	{

	}

	FVector2D operator+ (const FVector2D& RHS)
	{
		return FVector2D(this->X + RHS.X, this->Y + RHS.Y);
	}

	int X;
	int Y;
};
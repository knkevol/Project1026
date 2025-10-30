#pragma once
#include "SceneComponent.h"
#include <SDL3/SDL.h>

class UPaperFlipbookComponent : public USceneComponent
{
public:
	UPaperFlipbookComponent();
	virtual ~UPaperFlipbookComponent();

	virtual void Tick() override;
	virtual void Render() override;

	__forceinline char GetShape() { return Shape; }
	void SetShape(char InShape)
	{
		Shape = InShape;
	}

	__forceinline char GetZOder() const { return ZOrder; }
	void SetZOrder(int InZOrder)
	{
		ZOrder = InZOrder;
	}

protected:
	char Shape;
	int ZOrder;

//	SDL
public:
	SDL_Color Color = { 255, 255, 255, 255 };
};


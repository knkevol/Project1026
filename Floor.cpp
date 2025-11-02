#include "Floor.h"
#include "PaperFlipbookComponent.h"

AFloor::AFloor()
{
	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(0);
	PaperFlipbook->SetShape(' ');
	PaperFlipbook->SetOwner(this);
	PaperFlipbook->Color = SDL_Color{ 0, 0, 255, 0 };
	SetUpAttachment(PaperFlipbook);
}

AFloor::~AFloor()
{
}

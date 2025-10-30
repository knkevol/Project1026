#include "Floor.h"
#include "PaperFlipbookComponent.h"

AFloor::AFloor()
{
	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(0);
	SetUpAttachment(PaperFlipbook);
}

AFloor::~AFloor()
{
}

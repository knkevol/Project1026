#include "Floor.h"
#include "PaperFlipbookComponent.h"

AFloor::AFloor()
{
	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(0);
	PaperFlipbook->SetShape(' ');
	PaperFlipbook->SetOwner(this);
	SetUpAttachment(PaperFlipbook);
}

AFloor::~AFloor()
{
}

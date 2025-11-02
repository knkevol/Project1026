#include "Goal.h"

#include "PaperFlipbookComponent.h"
#include "Actor.h"

AGoal::AGoal()
{
	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(1);
	PaperFlipbook->SetShape('G');
	PaperFlipbook->SetOwner(this);
	SetUpAttachment(PaperFlipbook);
}

AGoal::~AGoal()
{
}

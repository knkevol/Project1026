#include "Goal.h"

#include "PaperFlipbookComponent.h"
#include "Actor.h"

AGoal::AGoal()
{
	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(1);
	SetUpAttachment(PaperFlipbook);
}

AGoal::~AGoal()
{
}

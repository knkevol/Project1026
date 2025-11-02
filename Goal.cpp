#include "Goal.h"

#include "PaperFlipbookComponent.h"
#include "Actor.h"

AGoal::AGoal()
{
	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(1);
	PaperFlipbook->SetShape('G');
	PaperFlipbook->SetOwner(this);
	PaperFlipbook->Color = SDL_Color{ 0, 255, 0, 0 };
	SetUpAttachment(PaperFlipbook);
}

AGoal::~AGoal()
{
}

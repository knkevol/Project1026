#include "Actor.h"
#include "PaperFlipbookComponent.h"

AActor::AActor()
{
	//PaperFlipbook = new UPaperFlipbookComponent;
	//PaperFlipbook->SetShape(' ');
	Location = 0, 0;
}

AActor::~AActor()
{
}

void AActor::Tick()
{
	
	
}

void AActor::SetUpAttachment(UComponent* InComp)
{
	Components.push_back(InComp);

}

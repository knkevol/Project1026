#include "Wall.h"

#include "CollisionComponent.h"
#include "PaperFlipbookComponent.h"
#include "Actor.h"

AWall::AWall()
{
	Collision = new UCollisionComponent;
	Collision->SetCollision(true);
	Collision->SetOverlap(true);
	Collision->SetOwner(this);
	SetUpAttachment(Collision);

	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(1);
	PaperFlipbook->SetShape('*');
	PaperFlipbook->SetOwner(this);
	PaperFlipbook->Color = SDL_Color{ 0, 0, 0, 0 };
	SetUpAttachment(PaperFlipbook);

}

AWall::~AWall()
{
}

#include "Wall.h"

#include "CollisionComponent.h"
#include "PaperFlipbookComponent.h"
#include "Actor.h"

AWall::AWall()
{
	Collision = new UCollisionComponent;
	Collision->SetCollision(true);
	Collision->SetOverlap(true);
	SetUpAttachment(Collision);

	PaperFlipbook = new UPaperFlipbookComponent;
	PaperFlipbook->SetZOrder(1);
	PaperFlipbook->SetShape('*');
	PaperFlipbook->SetOwner(this);
	SetUpAttachment(PaperFlipbook);

}

AWall::~AWall()
{
}

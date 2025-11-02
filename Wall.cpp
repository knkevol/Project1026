#include "Wall.h"

#include "CollisionComponent.h"
#include "PaperFlipbookComponent.h"
#include "Actor.h"

AWall::AWall()
{

	bool True = true;
	bool False = false;
	Collision = new UCollisionComponent;
	Collision->SetCollision(True);
	Collision->SetOverlap(False);
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

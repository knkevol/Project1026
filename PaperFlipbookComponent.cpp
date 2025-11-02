#include "PaperFlipbookComponent.h"
#include "Component.h"
#include <Windows.h>
#include "Actor.h"

#include "Engine.h"

UPaperFlipbookComponent::UPaperFlipbookComponent()
{
}

UPaperFlipbookComponent::~UPaperFlipbookComponent()
{
}

void UPaperFlipbookComponent::Tick()
{
}

void UPaperFlipbookComponent::Render()
{
    //COORD Position;

    //Position.X = GetOwner()->GetActorLocation().X;
    //Position.Y = GetOwner()->GetActorLocation().Y;

    //SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);

    //cout << GetShape();

    SDL_SetRenderDrawColor(GEngine->GetRenderer(), Color.r, Color.g, Color.b, Color.a);
    int SizeX = 30;
    int SizeY = 30;
    SDL_FRect DrawRect = {
        (float)GetOwner()->GetActorLocation().X * SizeX,
        (float)GetOwner()->GetActorLocation().Y * SizeY,
        (float)SizeX,
        (float)SizeY
    };
    SDL_RenderFillRect(GEngine->GetRenderer(), &DrawRect);
}




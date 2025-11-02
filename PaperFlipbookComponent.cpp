#include "PaperFlipbookComponent.h"
#include "Component.h"
#include <conio.h>
#include <Windows.h>
#include "Actor.h"

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
    COORD Position;

    Position.X = GetOwner()->GetActorLocation().X;
    Position.Y = GetOwner()->GetActorLocation().Y;

    SetConsoleCursorPosition((HANDLE)GetStdHandle(STD_OUTPUT_HANDLE), Position);

    cout << GetShape();
}




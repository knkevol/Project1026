#pragma once

class AActor;

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void Tick() = 0;

	AActor* GetOwner() const { return Owner; }
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};


#pragma once

#include <conio.h>
class UWorld;


class FEngine
{
protected:
	FEngine();

public:
	virtual ~FEngine();

	virtual void Init();
	virtual void Run();
	virtual void End();

	__forceinline int GetKeyCode() const { return KeyCode; }
	__forceinline UWorld* GetWorld() const { return World; }

	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}

		return Instance;
	}

protected:
	void Input();
	void Tick();
	void Render();

	static FEngine* Instance;

	class UWorld* World;

	bool bIsRunning = true;
	int KeyCode = 0;

};

#define GEngine FEngine::GetInstance()

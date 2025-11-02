#pragma once
#include <SDL3/SDL.h>
#include "Input.h"

#pragma comment(lib, "SDL3")

class UWorld;
class UInput;

class FEngine
{
protected:
	FEngine();

public:
	virtual ~FEngine();

	void OpenLevel();

	virtual void Init();
	virtual void Run();
	virtual void End();

	__forceinline int GetKeyCode() const { return UInput::GetKeyCode(); }
	__forceinline UWorld* GetWorld() const { return World; }

	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}

		return Instance;
	}

	__forceinline SDL_Renderer* GetRenderer() const { return MyRenderer; }
	__forceinline SDL_Event GetMyEvent() const { return MyEvent; }

protected:
	void Input();
	void Tick();
	void Render();

	static FEngine* Instance;

	class UWorld* World;

	bool bIsRunning = true;
	//int KeyCode = 0;

	//SDL
	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	UInput* InputDevice;

};

#define GEngine FEngine::GetInstance()

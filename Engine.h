#pragma once

#include <conio.h>


class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	void Init();
	void Run();
	void End();

	const int GetKeyCode() { return KeyCode; }

protected:
	void Input();
	void Tick();
	void Render();

	bool bIsRunning = true;
	int KeyCode;

};


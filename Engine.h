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

protected:
	void Input();
	void Tick();
	void Render();

	bool bIsRunning = true;
	int KeyCode;

};


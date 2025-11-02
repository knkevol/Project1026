#pragma once

class UInput
{
public:
	UInput();
	virtual ~UInput();

	void Tick();

	__forceinline static int GetKeyCode() { return KeyCode; }

protected:
	static int KeyCode;
};


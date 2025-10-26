#include <iostream>
#include "Engine.h"

using namespace std;

int main()
{
	FEngine* MyEngine = new FEngine();

	MyEngine->Init();
	MyEngine->Run();
	MyEngine->End();

	delete MyEngine;


	return 0;
}
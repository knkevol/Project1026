#include <iostream>
#include "Engine.h"
#include "Vector.h"


using namespace std;

int main()
{
	GEngine->Init();
	GEngine->Run();
	GEngine->End();

	delete GEngine;

	return 0;
}
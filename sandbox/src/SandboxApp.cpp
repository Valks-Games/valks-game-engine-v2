#include "Valk.h"
#include <iostream>

using namespace Valk;

int main() 
{
	Application* app = new Application();

	app->Run();

	delete app;

	return 0;
}
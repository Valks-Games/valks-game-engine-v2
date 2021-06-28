#include "Valk.h"
#include "Valk/Core/Log.h"
#include <iostream>

int main() 
{
	Valk::Log::Print();

	std::cout << "Hello world" << std::endl;
	std::cin.get();

	return 0;
}
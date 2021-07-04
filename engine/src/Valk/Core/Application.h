#pragma once

#include <vector>
#include "Script.h"

namespace Valk 
{
	class Application
	{
	public:
		std::vector<Script> m_Scripts;

	public:
		Application();
		~Application();

	public:
		void Run();
	};
}


#pragma once

#include <iostream>
#include <vector>

#include "Log.h"
#include "../Render/Shader.h"
#include "../Render/Mesh.h"
#include "../Msc/Common.h"

#include "../Math/Math.h"
#include "../Input/Input.h"
#include "../Window/Window.h"
#include "../Render/VertexBuffer.h"
#include "../Render/IndexBuffer.h"
#include "../Render/VertexArray.h"
#include "EngineScript.h"
#include "Time.h"
#include "GameObject.h"
#include "Transform.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Valk 
{
	class Application
	{
	public:
		Application();
		~Application();

	public:
		void Run();
	};
}


#pragma once

#include <glad/glad.h>

#include "../Math/math.h"

namespace Valk 
{
	class Mesh
	{
	private:
		//GLuint vaoId;
	public:
		std::vector<GLfloat> positions;
		std::vector<GLfloat> colors;
		std::vector<GLuint>  triangles;

		void Init();
	};
}

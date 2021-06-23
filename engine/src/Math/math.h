#pragma once

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace Valk::math
{
	struct vec2
	{
		double x;
		double y;
	};

	struct Vertex
	{
		glm::fvec3 position;
	};
}

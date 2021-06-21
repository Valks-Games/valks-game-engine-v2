#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../Math/Math.h"
#include "../Render/Mesh.h"

#include <vector>

namespace valk 
{
	class VertexBuffer 
	{
	private:
		GLuint m_ID;
		GLuint m_ComponentCount;

	public:
		VertexBuffer(Mesh mesh, GLuint componentCount);

	public:
		void bind() const;
		void unbind() const;
		inline GLuint getComponentCount() { return m_ComponentCount; }
	};
}
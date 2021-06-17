#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

namespace valk 
{
	class VertexBuffer 
	{
	private:
		GLuint m_ID;
		GLuint m_ComponentCount;

	public:
		VertexBuffer(std::vector<GLfloat> data, GLsizei count, GLuint componentCount);

	public:
		void bind() const;
		void unbind() const;
		inline GLuint getComponentCount() { return m_ComponentCount; }
	};
}
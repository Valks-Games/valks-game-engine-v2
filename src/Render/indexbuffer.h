#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace valk
{
	class IndexBuffer
	{
	private:
		GLuint m_ID;

	public:
		IndexBuffer(GLuint* data, GLsizei count);

	public:
		void bind() const;
		void unbind() const;
	};
}
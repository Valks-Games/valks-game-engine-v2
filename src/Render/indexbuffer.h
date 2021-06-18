#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

namespace valk
{
	class IndexBuffer
	{
	private:
		GLuint m_ID;
		GLsizei m_Count;

	public:
		IndexBuffer(std::vector<GLuint> data, GLsizei count);

	public:
		void bind() const;
		void unbind() const;
		inline GLsizei getCount() const { return m_Count; }
	};
}
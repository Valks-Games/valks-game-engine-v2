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
		void Bind() const;
		void Unbind() const;
		inline GLsizei GetCount() const { return m_Count; }
	};
}
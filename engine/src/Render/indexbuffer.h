#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

namespace Valk
{
	class IndexBuffer
	{
	private:
		GLuint id;
		GLsizei count;

	public:
		IndexBuffer(std::vector<GLuint> data, GLsizei count);

	public:
		void Bind() const;
		void Unbind() const;
		inline GLsizei GetCount() const { return count; }
	};
}
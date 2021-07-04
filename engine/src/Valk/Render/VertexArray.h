#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"

namespace Valk
{
	class VertexArray
	{
	private:
		GLuint id;
		std::vector<VertexBuffer*> vertexBuffers;

	public:
		VertexArray();
		~VertexArray();

	public:
		void AddBuffer(VertexBuffer* buffer, GLuint index);
		void Bind() const;
		void Unbind() const;
	};
}
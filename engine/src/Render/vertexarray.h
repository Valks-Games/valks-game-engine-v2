#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "VertexBuffer.h"

namespace valk
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
#include "vkpch.h"
#include "VertexArray.h"

namespace Valk 
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &id);
		glBindVertexArray(id);
	}

	VertexArray::~VertexArray() 
	{
		for (int i = 0; i < vertexBuffers.size(); i++) 
			delete vertexBuffers[i];
	}

	void VertexArray::AddBuffer(VertexBuffer* buffer, GLuint index) 
	{

	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(id);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}
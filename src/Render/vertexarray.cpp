#include "vertexarray.h"

namespace valk 
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ID);
	}

	VertexArray::~VertexArray() 
	{
		for (int i = 0; i < m_VertexBuffers.size(); i++) 
			delete m_VertexBuffers[i];
	}

	void VertexArray::addBuffer(VertexBuffer* buffer, GLuint index) 
	{
		bind();
		buffer->bind();

		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(index);

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_ID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}
}
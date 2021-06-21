#include "VertexArray.h"

namespace valk 
{
	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
	}

	VertexArray::~VertexArray() 
	{
		for (int i = 0; i < m_VertexBuffers.size(); i++) 
			delete m_VertexBuffers[i];
	}

	void VertexArray::AddBuffer(VertexBuffer* buffer, GLuint index) 
	{

	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(m_ID);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}
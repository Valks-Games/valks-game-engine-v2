#include "vertexbuffer.h"

namespace valk 
{
	VertexBuffer::VertexBuffer(std::vector<GLfloat> data, GLsizei count, GLuint componentCount) : m_ComponentCount(componentCount)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VertexBuffer::bind() const 
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void VertexBuffer:: unbind() const 
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

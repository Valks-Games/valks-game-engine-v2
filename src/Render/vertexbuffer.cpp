#include "vertexbuffer.h"

namespace valk 
{
	VertexBuffer::VertexBuffer(Mesh mesh, GLuint componentCount) : m_ComponentCount(componentCount)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, mesh.positions.size() * sizeof(GLfloat), mesh.positions.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, componentCount, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
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

#pragma once

#include <glad/glad.h>
#include <vector>

namespace valk 
{
	class Mesh
	{
	public:
		unsigned int VAO, VBO, EBO;
		GLuint m_TriIndexCount;

		Mesh(std::vector<GLfloat> vertices, std::vector<GLuint>, GLenum usage);

		void draw();
		void clean();
	};
}

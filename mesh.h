#pragma once

#include <glad/glad.h>

class Mesh 
{
public:
	unsigned int VAO, VBO, EBO;

	Mesh(float vertices[], int indices[]);

	void bind();
	void clean();
};
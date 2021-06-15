#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shader.h"
#include "mesh.h"
#include "common.h"

const int GLFW_VER_MAJOR = 4;
const int GLFW_VER_MINOR = 6;

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) 
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() 
{
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_VER_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_VER_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
	if (window == NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize the OpenGL loading library GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// Shaders
	Shader shader("shader.vert", "shader.frag");

	// Data
	float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	Mesh mesh(vertices, indices);

	/*unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);*/

	// Wireframe Mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		// Input
		processInput(window);

		// Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();
		//glBindVertexArray(VAO);
		mesh.bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Poll events and swap buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	//glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);
	mesh.clean();
    glDeleteProgram(shader.ID);

	glfwTerminate();

	return 0;
}
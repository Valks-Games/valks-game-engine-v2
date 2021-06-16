#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "../Render/shader.h"
#include "../Render/mesh.h"
#include "common.h"
#include "window.h"
#include "../Math/math.h"

const GLubyte GLFW_VER_MAJOR = 4;
const GLubyte GLFW_VER_MINOR = 6;

int main() 
{
	// Initialize GLFW
	glfwInit();

	// Set window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_VER_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_VER_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE); // Ignored for fullscreen
	glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE); // Ignored for windowed
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

	// Create a window (window must be created before GLAD is initialized)
	Window window("Engine", 800, 600);

	// Initialize the OpenGL loading library GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	window.printGLContext();
	window.updateViewport();
	
	// Shaders
	Shader shader("./src/Shaders/shader.vert", "./src/Shaders/shader.frag");

	std::vector<GLfloat> vertices{
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
	};

	std::vector<GLuint> indices{
		0, 1, 2
	};
	
	Mesh mesh(vertices, indices, GL_STATIC_DRAW);
	
	// Wireframe Mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	window.setClearColor(0, 0, 0, 1);

	glm::mat4 trans = glm::mat4(1.0f);
	//trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
	
	//
	trans = glm::scale(trans, glm::vec3(0.5f, 0.5, 0.5));


	while (!window.closed())
	{
		//window.displayFPS();

		float timeValue = static_cast<float>(glfwGetTime());
		float pulse = (sin(timeValue) / 2.0f) + 0.5f;

		trans = glm::rotate(trans, glm::radians(0.01f * pulse), glm::vec3(0.0, 0.0, 1.0));

		//std::cout << "(" << window.m_MousePosX << ", " << window.m_MousePosY << ")" << std::endl;

		window.clear();
		shader.use();
		//shader.setColor("color", pulse, 0, pulse, 1);
		shader.setMat4("transform", glm::value_ptr(trans));
		mesh.draw();

		window.update();
	}

	mesh.clean();
	shader.clean();

	glfwTerminate();

	return 0;
}
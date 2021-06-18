#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "Render/shader.h"
#include "Render/mesh.h"
#include "Msc/common.h"
#include "Window/window.h"
#include "Math/math.h"
#include "Input/input.h"
#include "Render/vertexbuffer.h"
#include "Render/indexbuffer.h"
#include "Render/vertexarray.h"

using namespace valk;

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
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE); // Ignored for fullscreen
	glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE); // Ignored for windowed
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Create a window (window must be created before GLAD is initialized)
	Window window("Engine", 800, 600);

	// Initialize the OpenGL loading library GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Input input(&window);
	window.printGLContext();
	window.updateViewport();

	// Shaders
	Shader shader("./res/Shaders/shader.vert", "./res/Shaders/shader.frag");

#if 0
	std::vector<GLfloat> vertices{
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
	};

	std::vector<GLuint> indices{
		0, 1, 2
	};
#else
	std::vector<GLfloat> vertices{
		 0.5f, -0.5f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f    // top 
	};

	std::vector<GLuint> indices{
		0, 1, 2
	};
#endif

#if 0
	Mesh mesh(vertices, indices, GL_STATIC_DRAW);
#else
	VertexArray vao;
	VertexBuffer* vbo = new VertexBuffer(vertices, 3 * 3, 3);
	IndexBuffer ibo(indices, 3);

	vao.addBuffer(vbo, 0);
#endif

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

		if (Input::getKeyDown(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.m_GLFWwindow, true);

		if (Input::getKeyUp(GLFW_KEY_F11))
			window.toggleFullscreen();

		if (Input::getMouseButtonUp(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "(" << Input::m_MousePosition.x << ", " << Input::m_MousePosition.y << ")" << std::endl;

		auto timeValue = static_cast<float>(glfwGetTime());
		auto pulse = (sin(timeValue) / 2.0f) + 0.5f;

		trans = glm::rotate(trans, glm::radians(0.01f * pulse), glm::vec3(0.0, 0.0, 1.0));

		window.clear();
		shader.use();
		//shader.setColor("color", pulse, 0, pulse, 1);
		shader.setMat4("transform", glm::value_ptr(trans));
#if 0
		mesh.draw();
#else
		vao.bind();
		ibo.bind();
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, 0);
		ibo.unbind();
		vao.unbind();
#endif

		window.update();
	}

#if 0
	mesh.clean();
#else
#endif
	shader.clean();

	glfwTerminate();

	return 0;
}

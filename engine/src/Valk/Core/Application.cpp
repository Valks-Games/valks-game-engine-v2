#include "vkpch.h"
#include "Application.h"

#include "Log.h"
#include "Render/Shader.h"
#include "Render/Mesh.h"
#include "Msc/Common.h"

#include "Math/Math.h"
#include "Input/Input.h"
#include "Window/Window.h"
#include "Render/VertexBuffer.h"
#include "Render/IndexBuffer.h"
#include "Render/VertexArray.h"
#include "EngineScript.h"
#include "Time.h"
#include "GameObject.h"
#include "Transform.h"
#include "Script.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define LOG(x) std::cout << x << std::endl;

const GLubyte GLFW_VER_MAJOR = 4;
const GLubyte GLFW_VER_MINOR = 6;

namespace Valk 
{
	Application::Application()
	{
		
	}

	void Application::Run() 
	{
		Log::Init();

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
			//return -1;
		}

		Input input(&window);
		window.PrintGLContext();
		window.UpdateViewport();

		// Shaders
		Shader shader("./res/Shaders/shader.vert", "./res/Shaders/shader.frag");

		static const GLfloat vertex_positions[]
		{
			-1.0f, -1.0f, 0.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f,
			-1.0f, 1.0f, 0.0f, 1.0f
		};

		static const GLfloat vertex_colors[]
		{
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 1.0f
		};

		static const GLushort vertex_indices[]
		{
			0, 1, 2
		};

		GLuint ebo[1];
		GLuint vao[1];
		GLuint vbo[1];

		// Setup element array buffer
		glGenBuffers(1, ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex_indices), vertex_indices, GL_STATIC_DRAW);

		// Setup vertex attributes
		glGenVertexArrays(1, vao);
		glBindVertexArray(vao[0]);

		glGenBuffers(1, vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_positions) + sizeof(vertex_colors), NULL, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0,                        sizeof(vertex_positions), vertex_positions);
		glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertex_positions), sizeof(vertex_colors)   , vertex_colors);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)sizeof(vertex_positions));
		glEnableVertexAttribArray(1);

		// Wireframe Mode
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		window.SetClearColor(0, 0, 0, 1);

		glm::mat4 trans = glm::mat4(1.0f);
		//trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));

		trans = glm::scale(trans, glm::vec3(0.5f, 0.5, 0.5));
		//trans = glm::translate(trans, glm::vec3(-3.0f, 0.0f, -5.0f));

		window.SetVSync(true);

		double lastFrameTime = 0.0f;

		while (!window.Closed())
		{
			double currentTime = glfwGetTime();
			double deltaTime = currentTime - lastFrameTime;
			lastFrameTime = currentTime;

			Time::deltaTime = deltaTime;

			//std::cout << (deltaTime * 1000) << " ms" << std::endl;

			//window.displayFPS();


			if (Input::GetKeyDown(GLFW_KEY_ESCAPE))
				glfwSetWindowShouldClose(window.GLFWwindow, true);

			if (Input::GetKeyUp(GLFW_KEY_F11))
				window.ToggleFullscreen();

			if (Input::GetMouseButtonUp(GLFW_MOUSE_BUTTON_LEFT))
				std::cout << "(" << Input::m_MousePosition.x << ", " << Input::m_MousePosition.y << ")" << std::endl;

			auto timeValue = static_cast<float>(glfwGetTime());
			auto pulse = (sin(timeValue) / 2.0f) + 0.5f;

			//trans = glm::rotate(trans, glm::radians<float>(100.0f * pulse * (float)deltaTime), glm::vec3(0.0, 0.0, 1.0));

			window.Clear();
			shader.Use();
			shader.SetColor("color", 1, pulse, 0, 1);
			shader.SetMat4("transform", glm::value_ptr(trans));

			//
			glDrawArrays(GL_TRIANGLES, 0, 3);
			//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, NULL);

			window.Update();
		}

		shader.Clean();

		glfwTerminate();
	}

	Application::~Application() 
	{
		
	}
}

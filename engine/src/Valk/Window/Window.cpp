#include "vkpch.h"
#include "window.h"

namespace Valk 
{
	Window::Window(const char* title, int width, int height)
	{
		GLFWwindow = glfwCreateWindow(width, height, title, NULL, NULL);
		windowWidth = width;
		windowHeight = height;
		fullscreen = false;
		monitor = glfwGetPrimaryMonitor();
		vidmode = glfwGetVideoMode(monitor);

		if (GLFWwindow == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		AlignToCenter(width, height);

		glfwMakeContextCurrent(GLFWwindow);
		glfwSetWindowUserPointer(GLFWwindow, this);

		previousTime = glfwGetTime();
	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(GLFWwindow);
	}

	void Window::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(GLFWwindow);
	}

	void Window::SetVSync(bool enabled) 
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		vsync = enabled;
	}

	void Window::SetClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) const
	{
		glClearColor(r, g, b, a);
	}

	void Window::ToggleFullscreen()
	{
		auto screenWidth = vidmode->width;
		auto screenHeight = vidmode->height;
		auto screenRefreshRate = vidmode->refreshRate;

		if (!fullscreen)
		{
			glfwSetWindowMonitor(GLFWwindow, monitor, 0, 0, screenWidth, screenHeight, screenRefreshRate);
			UpdateViewport();
		}
		else
		{
			glfwSetWindowMonitor(GLFWwindow, NULL, 0, 0, windowWidth, windowHeight, screenRefreshRate);
			AlignToCenter(windowWidth, windowHeight);
			UpdateViewport();
		}

		fullscreen = !fullscreen;
	}

	void Window::UpdateViewport() const
	{
		int windowWidth, windowHeight;
		glfwGetWindowSize(GLFWwindow, &windowWidth, &windowHeight);

		glViewport(0, 0, windowWidth, windowHeight);
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::PrintGLContext() const
	{
		std::cout << glGetString(GL_VENDOR) << std::endl;
		std::cout << glGetString(GL_RENDERER) << std::endl;
		std::cout << glGetString(GL_VERSION) << std::endl;
		std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	}

	void Window::DisplayFPS()
	{
		auto currentTime = glfwGetTime();
		frameCount++;

		if (currentTime - previousTime >= 1.0f)
		{
			std::cout << frameCount << std::endl;

			frameCount = 0;
			previousTime = currentTime;
		}
	}

	void Window::AlignToCenter(int windowWidth, int windowHeight) const
	{
		auto screenWidth = vidmode->width;
		auto screenHeight = vidmode->height;

		int monitorX, monitorY;
		glfwGetMonitorPos(monitor, &monitorX, &monitorY);

		auto centerX = monitorX + (screenWidth - windowWidth) / 2;
		auto centerY = monitorY + (screenHeight - windowHeight) / 2;

		glfwSetWindowPos(GLFWwindow, centerX, centerY);
	}
}

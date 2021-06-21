#include "window.h"

namespace valk 
{
	Window::Window(const char* title, int width, int height)
	{
		m_GLFWwindow = glfwCreateWindow(width, height, title, NULL, NULL);
		m_WindowWidth = width;
		m_WindowHeight = height;
		m_Fullscreen = false;
		m_Monitor = glfwGetPrimaryMonitor();
		m_Vidmode = glfwGetVideoMode(m_Monitor);

		if (m_GLFWwindow == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
		}

		AlignToCenter(width, height);

		glfwMakeContextCurrent(m_GLFWwindow);
		glfwSetWindowUserPointer(m_GLFWwindow, this);

		m_PreviousTime = glfwGetTime();
	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(m_GLFWwindow);
	}

	void Window::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(m_GLFWwindow);
	}

	void Window::SetVSync(bool enabled) 
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_VSync = enabled;
	}

	void Window::SetClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) const
	{
		glClearColor(r, g, b, a);
	}

	void Window::ToggleFullscreen()
	{
		auto screenWidth = m_Vidmode->width;
		auto screenHeight = m_Vidmode->height;
		auto screenRefreshRate = m_Vidmode->refreshRate;

		if (!m_Fullscreen)
		{
			glfwSetWindowMonitor(m_GLFWwindow, m_Monitor, 0, 0, screenWidth, screenHeight, screenRefreshRate);
			UpdateViewport();
		}
		else
		{
			glfwSetWindowMonitor(m_GLFWwindow, NULL, 0, 0, m_WindowWidth, m_WindowHeight, screenRefreshRate);
			AlignToCenter(m_WindowWidth, m_WindowHeight);
			UpdateViewport();
		}

		m_Fullscreen = !m_Fullscreen;
	}

	void Window::UpdateViewport() const
	{
		int windowWidth, windowHeight;
		glfwGetWindowSize(m_GLFWwindow, &windowWidth, &windowHeight);

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
		m_FrameCount++;

		if (currentTime - m_PreviousTime >= 1.0f)
		{
			std::cout << m_FrameCount << std::endl;

			m_FrameCount = 0;
			m_PreviousTime = currentTime;
		}
	}

	void Window::AlignToCenter(int windowWidth, int windowHeight) const
	{
		auto screenWidth = m_Vidmode->width;
		auto screenHeight = m_Vidmode->height;

		int monitorX, monitorY;
		glfwGetMonitorPos(m_Monitor, &monitorX, &monitorY);

		auto centerX = monitorX + (screenWidth - windowWidth) / 2;
		auto centerY = monitorY + (screenHeight - windowHeight) / 2;

		glfwSetWindowPos(m_GLFWwindow, centerX, centerY);
	}
}

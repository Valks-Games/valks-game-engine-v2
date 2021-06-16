#include "window.h"

Window::Window(const char* title, int width, int height)
{
	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
	m_WindowWidth = width;
	m_WindowHeight = height;
	m_Fullscreen = false;
	m_Monitor = glfwGetPrimaryMonitor();
	m_Vidmode = glfwGetVideoMode(m_Monitor);

	if (m_Window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}

	alignToCenter(width, height);

	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, this);

	initializeCallbacks();

	m_PreviousTime = glfwGetTime();
}

void Window::initializeCallbacks()
{
	glfwSetErrorCallback(errorCallback);
	glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);
	glfwSetKeyCallback(m_Window, keyCallback);
	glfwSetWindowCloseCallback(m_Window, windowCloseCallback);
	glfwSetCharCallback(m_Window, characterCallback);
	glfwSetCursorPosCallback(m_Window, cursorPositionCallback);
	glfwSetCursorEnterCallback(m_Window, cursorEnterCallback);
}

bool Window::closed()
{
	return glfwWindowShouldClose(m_Window);
}

void Window::update() 
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void Window::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

void Window::toggleFullscreen() 
{
	int screenWidth = m_Vidmode->width;
	int screenHeight = m_Vidmode->height;
	int screenRefreshRate = m_Vidmode->refreshRate;

	if (!m_Fullscreen) 
	{
		glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, screenWidth, screenHeight, screenRefreshRate);
		updateViewport();
	}
	else 
	{
		glfwSetWindowMonitor(m_Window, NULL, 0, 0, m_WindowWidth, m_WindowHeight, screenRefreshRate);
		alignToCenter(m_WindowWidth, m_WindowHeight);
		updateViewport();
	}

	m_Fullscreen = !m_Fullscreen;
}

void Window::updateViewport() 
{
	int windowWidth, windowHeight;
	glfwGetWindowSize(m_Window, &windowWidth, &windowHeight);

	glViewport(0, 0, windowWidth, windowHeight);
}

void Window::clear() 
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::printGLContext() 
{
	std::cout << glGetString(GL_VENDOR) << std::endl;
	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void Window::displayFPS() 
{
	double currentTime = glfwGetTime();
	m_FrameCount++;

	if (currentTime - m_PreviousTime >= 1.0f)
	{
		std::cout << m_FrameCount << std::endl;

		m_FrameCount = 0;
		m_PreviousTime = currentTime;
	}
}

void Window::alignToCenter(int windowWidth, int windowHeight) 
{
	int screenWidth = m_Vidmode->width;
	int screenHeight = m_Vidmode->height;

	int monitorX, monitorY;
	glfwGetMonitorPos(m_Monitor, &monitorX, &monitorY);

	int centerX = monitorX + (screenWidth - windowWidth) / 2;
	int centerY = monitorY + (screenHeight - windowHeight) / 2;
	
	glfwSetWindowPos(m_Window, centerX, centerY);
}

// GLFW_CURSOR_NORMAL, GLFW_CURSOR_HIDDEN, GLFW_CURSOR_DISABLED
void Window::setCursorMode(GLenum mode) 
{
	glfwSetInputMode(m_Window, GLFW_CURSOR, mode);
}

// Callbacks
void errorCallback(int code, const char* description) 
{
	std::cout << "ERROR: " << code << " " << description << std::endl;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (action != GLFW_PRESS)
		return;

	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(win->m_Window, true);

	if (key == GLFW_KEY_F11)
		win->toggleFullscreen();
}

void windowCloseCallback(GLFWwindow* window) 
{
	//glfwSetWindowShouldClose(window, GLFW_FALSE);
}

void characterCallback(GLFWwindow* window, unsigned int codepoint) 
{
	std::cout << codepoint << std::endl;
}

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) 
{
	auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));

	win->m_MousePosX = xpos;
	win->m_MousePosY = ypos;
}

void cursorEnterCallback(GLFWwindow* window, int entered) 
{
	if (entered) 
	{
		// cursor entered window
	}
	else 
	{
		// cursor left window
	}
}
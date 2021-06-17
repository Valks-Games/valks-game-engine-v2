#include "input.h"

namespace valk 
{
	Input::Input(Window* window) : m_CursorInWindow(false)
	{
		m_Window = window->m_GLFWwindow;

		glfwSetErrorCallback(errorCallback);
		glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);
		glfwSetKeyCallback(m_Window, keyCallback);
		glfwSetWindowCloseCallback(m_Window, windowCloseCallback);
		glfwSetCharCallback(m_Window, characterCallback);
		glfwSetCursorPosCallback(m_Window, cursorPositionCallback);
		glfwSetCursorEnterCallback(m_Window, cursorEnterCallback);
		glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
		glfwSetScrollCallback(m_Window, scrollCallback);
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
		Input::m_Keys[key] = action == GLFW_PRESS;
		Input::m_KeysDown[key] = action == GLFW_PRESS;
		Input::m_KeysUp[key] = action == GLFW_RELEASE;
	}

	bool Input::getKeyDown(unsigned int keycode)
	{
		if (m_KeysDown[keycode])
		{
			m_KeysDown[keycode] = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Input::getKeyUp(unsigned int keycode)
	{
		if (m_KeysUp[keycode])
		{
			m_KeysUp[keycode] = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Input::getKey(unsigned int keycode)
	{
		return m_Keys[keycode];
	}

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Input::m_Buttons[button] = action == GLFW_PRESS;
		Input::m_ButtonsDown[button] = action == GLFW_PRESS;
		Input::m_ButtonsUp[button] = action == GLFW_RELEASE;
	}

	bool Input::getMouseButtonDown(unsigned int button) 
	{
		if (m_ButtonsDown[button])
		{
			m_ButtonsDown[button] = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Input::getMouseButtonUp(unsigned int button)
	{
		if (m_ButtonsUp[button])
		{
			m_ButtonsUp[button] = false;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Input::getMouseButton(unsigned int button)
	{
		return m_Buttons[button];
	}

	void windowCloseCallback(GLFWwindow* window)
	{
		//glfwSetWindowShouldClose(window, GLFW_FALSE);
	}

	void characterCallback(GLFWwindow* window, unsigned int codepoint)
	{
		//std::cout << codepoint << std::endl;
	}

	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		auto win = static_cast<Input*>(glfwGetWindowUserPointer(window));

		Input::m_MousePosition.x = xpos;
		Input::m_MousePosition.y = ypos;
	}

	void cursorEnterCallback(GLFWwindow* window, int entered)
	{
		auto win = static_cast<Input*>(glfwGetWindowUserPointer(window));

		if (entered)
			win->m_CursorInWindow = true;
		else
			win->m_CursorInWindow = false;
	}

	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{

	}
}

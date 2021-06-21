#include "input.h"

namespace valk 
{
	Input::Input(Window* window) : m_CursorInWindow(false)
	{
		m_Window = window->m_GLFWwindow;

		glfwSetErrorCallback(ErrorCallback);
		glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
		glfwSetKeyCallback(m_Window, KeyCallback);
		glfwSetWindowCloseCallback(m_Window, WindowCloseCallback);
		glfwSetCharCallback(m_Window, CharacterCallback);
		glfwSetCursorPosCallback(m_Window, CursorPositionCallback);
		glfwSetCursorEnterCallback(m_Window, CursorEnterCallback);
		glfwSetMouseButtonCallback(m_Window, MouseButtonCallback);
		glfwSetScrollCallback(m_Window, ScrollCallback);
	}

	// Callbacks
	void ErrorCallback(int code, const char* description)
	{
		std::cout << "ERROR: " << code << " " << description << std::endl;
	}

	void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Input::m_Keys[key] = action == GLFW_PRESS;
		Input::m_KeysDown[key] = action == GLFW_PRESS;
		Input::m_KeysUp[key] = action == GLFW_RELEASE;
	}

	bool Input::GetKeyDown(unsigned int keycode)
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

	bool Input::GetKeyUp(unsigned int keycode)
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

	bool Input::GetKey(unsigned int keycode)
	{
		return m_Keys[keycode];
	}

	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Input::m_Buttons[button] = action == GLFW_PRESS;
		Input::m_ButtonsDown[button] = action == GLFW_PRESS;
		Input::m_ButtonsUp[button] = action == GLFW_RELEASE;
	}

	bool Input::GetMouseButtonDown(unsigned int button) 
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

	bool Input::GetMouseButtonUp(unsigned int button)
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

	bool Input::GetMouseButton(unsigned int button)
	{
		return m_Buttons[button];
	}

	void WindowCloseCallback(GLFWwindow* window)
	{
		//glfwSetWindowShouldClose(window, GLFW_FALSE);
	}

	void CharacterCallback(GLFWwindow* window, unsigned int codepoint)
	{
		//std::cout << codepoint << std::endl;
	}

	static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		auto win = static_cast<Input*>(glfwGetWindowUserPointer(window));

		Input::m_MousePosition.x = xpos;
		Input::m_MousePosition.y = ypos;
	}

	void CursorEnterCallback(GLFWwindow* window, int entered)
	{
		auto win = static_cast<Input*>(glfwGetWindowUserPointer(window));

		if (entered)
			win->m_CursorInWindow = true;
		else
			win->m_CursorInWindow = false;
	}

	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{

	}
}

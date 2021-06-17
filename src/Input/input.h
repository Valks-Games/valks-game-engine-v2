#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "../Window/window.h"
#include "../Math/math.h"

using namespace valk::math;

namespace valk 
{
	constexpr unsigned int MAX_KEYS = 1024;
	constexpr unsigned int MAX_BUTTONS = 32;

	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	void errorCallback(int code, const char* description);
	void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void windowCloseCallback(GLFWwindow* window);
	void characterCallback(GLFWwindow* window, unsigned int codepoint);
	void cursorEnterCallback(GLFWwindow* window, int entered);
	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

	class Input
	{
	public:
		GLFWwindow* m_Window;

		bool m_CursorInWindow;

		static inline vec2 m_MousePosition;
		static inline bool m_KeysDown[MAX_KEYS];
		static inline bool m_Keys[MAX_KEYS];
		static inline bool m_KeysUp[MAX_KEYS];
		static inline bool m_Buttons[MAX_BUTTONS];
		static inline bool m_ButtonsDown[MAX_BUTTONS];
		static inline bool m_ButtonsUp[MAX_BUTTONS];

	public:
		Input(Window* window);

	public:
		static bool getKey(unsigned int keycode);
		static bool getKeyDown(unsigned int keycode);
		static bool getKeyUp(unsigned int keycode);
		static bool getMouseButton(unsigned int button);
		static bool getMouseButtonDown(unsigned int button);
		static bool getMouseButtonUp(unsigned int button);
	};
}

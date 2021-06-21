#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "../Window/Window.h"
#include "../Math/Math.h"

using namespace valk::math;

namespace valk 
{
	constexpr unsigned int MAX_KEYS = 1024;
	constexpr unsigned int MAX_BUTTONS = 32;

	static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	void ErrorCallback(int code, const char* description);
	void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void WindowCloseCallback(GLFWwindow* window);
	void CharacterCallback(GLFWwindow* window, unsigned int codepoint);
	void CursorEnterCallback(GLFWwindow* window, int entered);
	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

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
		static bool GetKey(unsigned int keycode);
		static bool GetKeyDown(unsigned int keycode);
		static bool GetKeyUp(unsigned int keycode);
		static bool GetMouseButton(unsigned int button);
		static bool GetMouseButtonDown(unsigned int button);
		static bool GetMouseButtonUp(unsigned int button);
	};
}

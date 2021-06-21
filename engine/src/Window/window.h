#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace valk 
{
	class Window
	{
	public:
		GLFWwindow* m_GLFWwindow;

		int  m_WindowWidth, m_WindowHeight;
		bool m_Fullscreen;
		bool m_VSync;

		const GLFWvidmode* m_Vidmode;
		GLFWmonitor* m_Monitor;

		// FPS
		double m_PreviousTime;
		int    m_FrameCount;

	public:
		Window(const char* title, int width, int height);

	public:
		bool closed() const;
		void update() const;
		void setVSync(bool enabled);
		void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) const;
		void clear() const;
		void printGLContext() const;
		void toggleFullscreen();
		void updateViewport() const;
		void displayFPS();

	private:
		void alignToCenter(int windowWidth, int windowHeight) const;
	};
}

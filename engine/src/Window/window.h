#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace valk 
{
	class Window
	{
	public:
		GLFWwindow* GLFWwindow;

		int  windowWidth, windowHeight;
		bool fullscreen;
		bool vsync;

		const GLFWvidmode* vidmode;
		GLFWmonitor* monitor;

		// FPS
		double previousTime;
		int    frameCount;

	public:
		Window(const char* title, int width, int height);

	public:
		bool Closed() const;
		void Update() const;
		void SetVSync(bool enabled);
		void SetClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) const;
		void Clear() const;
		void PrintGLContext() const;
		void ToggleFullscreen();
		void UpdateViewport() const;
		void DisplayFPS();

	private:
		void AlignToCenter(int windowWidth, int windowHeight) const;
	};
}

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

void errorCallback(int code, const char* description);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void windowCloseCallback(GLFWwindow* window);
void characterCallback(GLFWwindow* window, unsigned int codepoint);
static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
void cursorEnterCallback(GLFWwindow* window, int entered);

class Window
{
public:
	GLFWwindow* m_Window;
	bool m_Fullscreen;
	int m_WindowWidth, m_WindowHeight;
	double m_MousePosX, m_MousePosY;

	const GLFWvidmode* m_Vidmode;
	GLFWmonitor* m_Monitor;

	// FPS
	double m_PreviousTime;
	int m_FrameCount;

public:
	Window(const char* title, int width, int height);

private:
	void initializeCallbacks();
	void alignToCenter(int windowWidth, int windowHeight);

public:
	bool closed();
	void update();
	void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	void clear();
	void printGLContext();
	void toggleFullscreen();
	void updateViewport();
	void displayFPS();
	void setCursorMode(GLenum mode);
};
#include "Application.h"

const GLubyte GLFW_VER_MAJOR = 4;
const GLubyte GLFW_VER_MINOR = 6;

namespace Valk 
{
	Application::Application()
	{
		
	}

	void Application::Run() 
	{
		Log::Init();

		// Initialize GLFW
		glfwInit();

		// Set window hints
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_VER_MAJOR);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_VER_MINOR);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
		glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE); // Ignored for fullscreen
		glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE); // Ignored for windowed
		glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 4);

		// Create a window (window must be created before GLAD is initialized)
		Window window("Engine", 800, 600);

		// Initialize the OpenGL loading library GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			//return -1;
		}

		Input input(&window);
		window.PrintGLContext();
		window.UpdateViewport();

		// Shaders
		Shader shader("./res/Shaders/shader.vert", "./res/Shaders/shader.frag");

#if 0
		std::vector<GLfloat> vertices{
			 0.5f, -0.5f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   // bottom left
			 0.0f,  0.5f, 0.0f    // top 
		};

		std::vector<GLuint> indices{
			0, 1, 2
		};
#else
		std::vector<GLfloat> positions
		{
				0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 1.0f,
				0.0f,  0.5f, 0.0f, 1.0f
		};

		std::vector<GLfloat> colors
		{
			1.0f, 0.0f, 0.0f, 1.0f,
			0.0f, 1.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f
		};

		std::vector<GLfloat> data;


		for (GLfloat i : colors)
			data.push_back(i);

		//for (GLfloat i : data)
			//std::cout << i << std::endl;

		std::vector<GLuint> triangles
		{
			0, 1, 2
		};

		std::vector<GLfloat> newVec;

		newVec.push_back(positions[0]);

		//puts(newVec[0]);

		Mesh mesh;
		mesh.positions = positions;
		mesh.colors = colors;
		mesh.triangles = triangles;

#endif

#if 0
		Mesh mesh(vertices, indices, GL_STATIC_DRAW);
#else
		VertexArray vao;
		VertexBuffer* vbo = new VertexBuffer(mesh, 4);
		IndexBuffer ibo(mesh.triangles, 3);
		vao.Unbind();
#endif

		// Wireframe Mode
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		window.SetClearColor(0, 0, 0, 1);

		glm::mat4 trans = glm::mat4(1.0f);
		//trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));

		trans = glm::scale(trans, glm::vec3(0.5f, 0.5, 0.5));

		window.SetVSync(true);

		double lastFrameTime = 0.0f;

		while (!window.Closed())
		{
			double currentTime = glfwGetTime();
			double deltaTime = currentTime - lastFrameTime;
			lastFrameTime = currentTime;

			Time::deltaTime = deltaTime;

			//std::cout << (deltaTime * 1000) << " ms" << std::endl;

			//window.displayFPS();



			




			if (Input::GetKeyDown(GLFW_KEY_ESCAPE))
				glfwSetWindowShouldClose(window.GLFWwindow, true);

			if (Input::GetKeyUp(GLFW_KEY_F11))
				window.ToggleFullscreen();

			if (Input::GetMouseButtonUp(GLFW_MOUSE_BUTTON_LEFT))
				std::cout << "(" << Input::m_MousePosition.x << ", " << Input::m_MousePosition.y << ")" << std::endl;

			auto timeValue = static_cast<float>(glfwGetTime());
			auto pulse = (sin(timeValue) / 2.0f) + 0.5f;

			trans = glm::rotate(trans, glm::radians<float>(100.0f * pulse * (float)deltaTime), glm::vec3(0.0, 0.0, 1.0));

			window.Clear();
			shader.Use();
			shader.SetColor("color", 1, pulse, 0, 1);
			shader.SetMat4("transform", glm::value_ptr(trans));
#if 0
			mesh.draw();
#else
			vao.Bind();
			glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
			vao.Unbind();
#endif

			window.Update();
		}

#if 0
		mesh.clean();
#else
#endif
		shader.Clean();

		glfwTerminate();
	}

	Application::~Application() 
	{
		
	}
}

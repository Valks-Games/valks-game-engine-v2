#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Math/math.h"

namespace valk 
{
	enum class ShaderType { VERTEX, FRAGMENT, PROGRAM };

	class Shader
	{
	public:
		unsigned int ID; // the program ID

		Shader(const char* vertexPath, const char* fragmentPath);

		void use();

		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		void setColor(const std::string& name, float r, float g, float b, float a) const;
		void setMat4(const std::string& name, glm::f32* value) const;

		void clean() const;

	private:
		void checkCompileErrors(unsigned int shader, ShaderType type) const;
	};
}

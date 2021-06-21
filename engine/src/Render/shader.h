#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Math/Math.h"

namespace valk 
{
	enum class ShaderType { VERTEX, FRAGMENT, PROGRAM };

	class Shader
	{
	public:
		unsigned int ID; // the program ID

		Shader(const char* vertexPath, const char* fragmentPath);

		void Use();

		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
		void SetColor(const std::string& name, float r, float g, float b, float a) const;
		void SetMat4(const std::string& name, glm::f32* value) const;

		void Clean() const;

	private:
		void CheckCompileErrors(unsigned int shader, ShaderType type) const;
	};
}

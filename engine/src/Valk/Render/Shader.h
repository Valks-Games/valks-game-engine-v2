#pragma once

#include "../Math/Math.h"

namespace Valk 
{
	enum class ShaderType { VERTEX, FRAGMENT, PROGRAM };

	class Shader
	{
	public:
		unsigned int id; // the program ID

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

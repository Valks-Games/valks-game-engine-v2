#include "shader.h"
#include "../Core/common.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath) : ID(0)
{
    std::ifstream vShaderFile(vertexPath);
    std::ifstream fShaderFile(fragmentPath);
    std::stringstream vShaderStream, fShaderStream;

    if (vShaderFile.fail())
    {
        std::cerr << "ERROR: Could not open file: \"" << vertexPath << "\"" << std::endl;
        return;
    }

    if (fShaderFile.fail())
    {
        std::cerr << "ERROR: Could not open file: \"" << fragmentPath << "\"" << std::endl;
        return;
    }
    
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vShaderFile.close();
    fShaderFile.close();

    std::string vertexCode;
    std::string fragmentCode;

    std::string version = "#version " + std::to_string(GLFW_VER_MAJOR) + std::to_string(GLFW_VER_MINOR) + "0 core\n\n";

    vertexCode = version + vShaderStream.str();
    fragmentCode = version + fShaderStream.str();

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // Compile shaders
    unsigned int vertex, fragment;

    // Vertex
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, ShaderType::VERTEX);

    // Fragment
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, ShaderType::FRAGMENT);

    // Create shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, ShaderType::PROGRAM);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() 
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const 
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const 
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const 
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setColor(const std::string& name, float r, float g, float b, float a) const
{
    GLint location = glGetUniformLocation(ID, name.c_str());
    glUniform4f(location, r, g, b, a);
}

void Shader::setMat4(const std::string& name, glm::f32* value) 
{
    unsigned int transformLoc = glGetUniformLocation(ID, name.c_str());
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value);
}

void Shader::clean() 
{
    glDeleteProgram(ID);
}

void Shader::checkCompileErrors(unsigned int shader, ShaderType type)
{
    int       success;
    const int infoSize = 1024;
    char      infoLog[infoSize];

    if (type != ShaderType::PROGRAM)
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, infoSize, NULL, infoLog);
            std::cout << infoLog;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, infoSize, NULL, infoLog);
            std::cout << infoLog;
        }
    }
}
#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.hpp"
#include "UtilsGL.hpp"

Shader::Shader(const std::string& filepath) : Renderer_ID(0)
{
    const ShaderSources source = ParseShader(filepath);
    Renderer_ID = CreateShader(source.vertexShader, source.fragmentShader);
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(Renderer_ID));
}

void Shader::Bind() const
{
    GLCall(glUseProgram(Renderer_ID));
}

void Shader::Unbind() const
{
    GLCall(glUseProgram(0));
}

void Shader::SetUniform1i(const std::string& name, int value)
{
    GLCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUniform1f(const std::string& name, float value)
{
    GLCall(glUniform1f(GetUniformLocation(name), value));
}

void Shader::SetUniform4f(const std::string& name, float r, float g, float b, float a)
{
    GLCall(glUniform4f(GetUniformLocation(name), r, g, b, a));
}

void Shader::SetUniformMat4f(const std::string& name, const Matrix4& mat)
{
    GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &mat.x.x));
}

int Shader::GetUniformLocation(const std::string& name)
{
    if (UniformLocationCache.find(name) != UniformLocationCache.end()) {
        return UniformLocationCache[name];
    }

    const int location = glGetUniformLocation(Renderer_ID, name.c_str()); // Returns -1 if the variable is not used
    if (location == -1) {
        std::cout << "[WARNING] Uniform : " << name << " not found in shader code." << std::endl;
    }
     UniformLocationCache[name] = location;



    return location;
}

ShaderSources Shader::ParseShader(const std::string& filepath) {
    /* Parse a shader file into two shaders, a vertex and a fragment*/

    std::ifstream stream(filepath);

    enum ShaderType {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };


    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;


    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        }
        else {

            ss[(int)type] << line << std::endl;
        }
    }

    return { ss[VERTEX].str(), ss[FRAGMENT].str() };

}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    const char* src = source.c_str();

    // Alloc for shader
    unsigned int id = glCreateShader(type);

    // Load shader
    GLCall(glShaderSource(id, 1, &src, nullptr));

    // Compile it
    GLCall(glCompileShader(id));

    // Handle compile error
    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if (GL_FALSE == result) {
        int length;
        GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &length));
        char* message = (char*)_malloca(length * sizeof(char));

        GLCall(glGetShaderInfoLog(id, length, &length, message));
        std::cout << "Failed shader compilation" << std::endl;
        std::cout << "Shader : " << (type == GL_VERTEX_SHADER ? "Vertex Shader" : "Fragment Shader") << std::endl;
        std::cout << message << std::endl;
        _freea(message);
    }

    return id;
}


unsigned int Shader::CompileShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));

    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));

    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

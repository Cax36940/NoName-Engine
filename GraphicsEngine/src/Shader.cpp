#include <iostream>

#include "Shader.hpp"
#include "UtilsGL.hpp"

Shader::Shader(const ShaderSources& sources) : Renderer_ID(UINT32_MAX)
{
    Renderer_ID = CreateShader(sources.vertexShader, sources.fragmentShader);
}

Shader::Shader(Shader&& shader) noexcept : Renderer_ID(shader.Renderer_ID)
{
    shader.Renderer_ID = UINT32_MAX;
}

Shader& Shader::operator=(Shader&& shader) noexcept
{
    if (Renderer_ID != UINT32_MAX) {
        GLCall(glDeleteProgram(Renderer_ID));
    }
    Renderer_ID = shader.Renderer_ID;
    shader.Renderer_ID = UINT32_MAX;
    return *this;
}

Shader::~Shader()
{
    if (Renderer_ID != UINT32_MAX) {
        GLCall(glDeleteProgram(Renderer_ID));
    }
}

bool Shader::operator==(const Shader& shader) const
{
    return Renderer_ID == shader.Renderer_ID;
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

void Shader::SetUniform3f(const std::string& name, float x, float y, float z)
{
    GLCall(glUniform3f(GetUniformLocation(name), x, y, z));
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

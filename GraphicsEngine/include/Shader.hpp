#pragma once

#include <string>
#include <unordered_map>
#include "Matrix4.hpp"

typedef struct ShaderSources {
	std::string vertexShader;
	std::string fragmentShader;
} ShaderSources ;

class Shader {
private:
	unsigned int Renderer_ID; // Internal renderer id of the object
	std::unordered_map<std::string, int> UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float r, float g, float b, float a);
	void SetUniformMat4f(const std::string& name, const Matrix4& mat);

private :
	int GetUniformLocation(const std::string& name);
	ShaderSources ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

};
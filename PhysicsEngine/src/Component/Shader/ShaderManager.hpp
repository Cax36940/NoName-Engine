#pragma once
#include <unordered_map>

#include "Shader.hpp"

class ShaderManager {
private:
	static std::unordered_map<std::string, Shader> shaders;
	static std::unordered_map<std::string, int> shader_ref_count;

	static ShaderSources parse_shader(const std::string& filepath);

public:

	static Shader& get_shader_ref(const std::string& shader_path);
	static void remove_shader(const Shader& shader);
	static void clear();
};
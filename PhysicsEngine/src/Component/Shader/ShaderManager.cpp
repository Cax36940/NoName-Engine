#include <iostream>
#include <fstream>
#include <sstream>

#include "ShaderManager.hpp"

std::unordered_map<std::string, Shader> ShaderManager::shaders;
std::unordered_map<std::string, int> ShaderManager::shader_ref_count;

ShaderSources ShaderManager::parse_shader(const std::string& filepath) {
    /* Parse a shader file into two shaders, a vertex and a fragment*/

    std::ifstream stream(filepath);

    if (!stream.is_open()) {
        std::cerr << "[ERROR] Could not open file: " << filepath << std::endl;
    }

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

Shader& ShaderManager::get_shader_ref(const std::string& shader_path)
{
    auto shader = shaders.find(shader_path);
    if (shader != shaders.end()) {
        return shader->second;
    }
    auto result = shaders.emplace(shader_path, parse_shader(shader_path));
    shader_ref_count.emplace(shader_path, 1);

    return result.first->second; // Return the Shader reference
}

void ShaderManager::remove_shader(const Shader& shader)
{
    for (const auto& registered_shader : shaders) {
        if (registered_shader.second == shader) {
            const std::string& shader_path = registered_shader.first;
            --shader_ref_count[shader_path];
            if (shader_ref_count[shader_path] == 0) {
                shader_ref_count.erase(shader_path);
                shaders.erase(shader_path);
            }
            return;
        }
    }

    std::cerr << "[WARNING] Try to remove an unexisting shader" << std::endl;
}

void ShaderManager::clear()
{
    shaders.clear();
}

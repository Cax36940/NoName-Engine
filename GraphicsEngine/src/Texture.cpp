#include <iostream>

#include "stb_image.hpp"

#include "Texture.hpp"
#include "UtilsGL.hpp"

Texture::Texture(const std::string& filepath) :
	Renderer_ID(0), FilePath(filepath), LocalBuffer(nullptr), Width(0), Height(0), BPP(0)
{
	stbi_set_flip_vertically_on_load(1);

	LocalBuffer = stbi_load(filepath.c_str(), &Width, &Height, &BPP, 4);

	GLCall(glGenTextures(1, &Renderer_ID));
	GLCall(glBindTexture(GL_TEXTURE_2D, Renderer_ID));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)); // Interpolation mode ?
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE)); // No texture tilling
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE)); // s -> x dir, t -> y dir


	if (LocalBuffer) { // Free the memory but it could be kept for sampling
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, LocalBuffer));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		stbi_image_free(LocalBuffer);
		LocalBuffer = nullptr;
	}

}

Texture::~Texture()
{
	if (LocalBuffer) { // If it has not been freed already
		stbi_image_free(LocalBuffer);
		LocalBuffer = nullptr;
	}

	GLCall(glDeleteTextures(1, &Renderer_ID));

}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, Renderer_ID));
}

void Texture::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}

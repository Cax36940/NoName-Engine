#pragma once

#include <string>

class Texture {
private:
	unsigned int Renderer_ID; // Internal renderer id of the object
	std::string FilePath;
	unsigned char* LocalBuffer;
	int Width, Height, BPP; // Bits Per Pixel
public:
	Texture(const std::string& filepath);
	~Texture();

	void Bind(unsigned int slot) const;
	void Unbind() const;

	inline int GetWidth() const { return Width; }
	inline int GetHeight() const { return Height; }
};
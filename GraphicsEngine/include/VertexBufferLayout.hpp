#pragma once

#include <stdexcept>
#include <vector>

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSize(unsigned int type);
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> elements;
	unsigned int stride;

public:
	VertexBufferLayout() : stride(0) {}

	template<typename T>
	void Push(unsigned int count);

	template<>
	void Push<float>(unsigned int count);

	template<>
	void Push<unsigned int>(unsigned int count);

	template<>
	void Push<unsigned char>(unsigned int count);

	const std::vector<VertexBufferElement>& GetElements() const { return elements; }
	unsigned int GetStride() const { return stride; }

};
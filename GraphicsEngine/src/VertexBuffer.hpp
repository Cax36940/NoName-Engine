#pragma once

class VertexBuffer {
private:
	unsigned int Renderer_ID; // Internal renderer id of the object

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};
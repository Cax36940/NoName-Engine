#pragma once

class VertexBuffer;
class VertexBufferLayout;

class VertexArray {
private:
	unsigned int Renderer_ID; // Internal renderer id of the object
public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
};
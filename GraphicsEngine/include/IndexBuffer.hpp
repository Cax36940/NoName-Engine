#pragma once

class IndexBuffer {
private:
	unsigned int Renderer_ID; // Internal renderer id of the object
	unsigned int Count; // 
public:
	IndexBuffer() = delete;
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return Count; }
};
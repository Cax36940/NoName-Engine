#pragma once

class IndexBuffer {
private:
	unsigned int Renderer_ID; // Internal renderer id of the object
	unsigned int Count; // 
public:
	IndexBuffer();
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Setup(const unsigned int* data, unsigned int count);
	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return Count; }
};
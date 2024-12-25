#pragma once

class VertexArray;
class IndexBuffer;
class Shader;

class Renderer {
public:
	void Draw(const VertexArray& va, const IndexBuffer& indices, const Shader& shader) const;
	void Clear() const;
};
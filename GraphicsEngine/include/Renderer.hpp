#pragma once

class VertexArray;
class IndexBuffer;
class Shader;

namespace Renderer {
	void Draw(const VertexArray& va, const IndexBuffer& indices, const Shader& shader);
	void Clear();
}

#include "Renderer.hpp"

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"
#include "Renderer.hpp"
#include "UtilsGL.hpp"

void Renderer::Draw(const VertexArray& va, const IndexBuffer& indices, const Shader& shader) const
{
	va.Bind();
	indices.Bind();
	shader.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, indices.GetCount(), GL_UNSIGNED_INT, nullptr));

}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

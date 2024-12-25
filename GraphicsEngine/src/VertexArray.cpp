#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "UtilsGL.hpp"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &Renderer_ID)); // Create vao
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &Renderer_ID));
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(Renderer_ID)); // Bind vao to current vao
}

void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for (int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];

        // Enable attribute i of VAO (could be a color, a position...)
        GLCall(glEnableVertexAttribArray(i));

        // Tell OpenGL that attrib i of currently is :
        // 2 GL_FLOAT, they are not normalized, they are spaced by 8 bytes each, and the first one is at byte 0 
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset));// also links buffer with vao so only vao and index need to be bound to draw
        offset += element.count * VertexBufferElement::GetSize(element.type);
    }


}

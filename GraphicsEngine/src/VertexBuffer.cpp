#include <cstdint> // UINT32_MAX

#include "VertexBuffer.hpp"
#include "UtilsGL.hpp"

VertexBuffer::VertexBuffer() : Renderer_ID(UINT32_MAX) {}

VertexBuffer::VertexBuffer(const void* data, unsigned int size) : Renderer_ID(UINT32_MAX) {
    Setup(data, size);
}

VertexBuffer::~VertexBuffer() {
    if (Renderer_ID != UINT32_MAX) {
        GLCall(glDeleteBuffers(1, &Renderer_ID));
    }
}

void VertexBuffer::Setup(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &Renderer_ID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, Renderer_ID)); // Set the current buffer in which we are writting
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)); // Write inside the current buffer
}

void VertexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, Renderer_ID));
}

void VertexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

#include "VertexBuffer.hpp"
#include "UtilsGL.hpp"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    GLCall(glGenBuffers(1, &Renderer_ID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, Renderer_ID)); // Set the current buffer in which we are writting
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)); // Write inside the current buffer
}

VertexBuffer::~VertexBuffer() {
    GLCall(glDeleteBuffers(1, &Renderer_ID));
}

void VertexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, Renderer_ID));
}

void VertexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

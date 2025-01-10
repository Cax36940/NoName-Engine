#include <cstdint> // UINT32_MAX

#include "IndexBuffer.hpp"
#include "UtilsGL.hpp"

IndexBuffer::IndexBuffer() : Renderer_ID(UINT32_MAX), Count(0) {}

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : Renderer_ID(UINT32_MAX), Count(0) {
    Setup(data, count);
}

IndexBuffer::~IndexBuffer() {
    if (Renderer_ID != UINT32_MAX) {
        GLCall(glDeleteBuffers(1, &Renderer_ID));
    }
}

void IndexBuffer::Setup(const unsigned int* data, unsigned int count)
{
    Count = count;
    GLCall(glGenBuffers(1, &Renderer_ID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Renderer_ID)); // Set the current buffer in which we are writting
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW)); // Write inside the current buffer
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Renderer_ID));
}

void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

#include "VertexBufferLayout.hpp"
#include "UtilsGL.hpp"

unsigned int VertexBufferElement::GetSize(unsigned int type) {
		switch (type) {
		case GL_FLOAT:
			return sizeof(GLfloat);
		case GL_UNSIGNED_INT:
			return sizeof(GLuint);
		case GL_UNSIGNED_BYTE:
			return sizeof(GLubyte);
		}
		ASSERT(false);
		return 0;
}

template<typename T>
void VertexBufferLayout::Push(unsigned int count) {
	throw std::runtime_error("Try to push a type with no push function associated");
}

template<>
void VertexBufferLayout::Push<float>(unsigned int count) {
	elements.push_back({ GL_FLOAT, count, GL_FALSE });
	stride += count * sizeof(GLfloat);
}

template<>
void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
	elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	stride += count * sizeof(GLuint);
}

template<>
void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
	elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
	stride += count * sizeof(GLubyte);
}

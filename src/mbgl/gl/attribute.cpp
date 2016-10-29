#include <mbgl/gl/attribute.hpp>
#include <mbgl/gl/gl.hpp>

namespace mbgl {
namespace gl {

void bindAttribute(AttributeLocation location,
                   std::size_t count,
                   DataType type,
                   std::size_t vertexSize,
                   std::size_t vertexOffset,
                   std::size_t attributeOffset) {
    MBGL_CHECK_ERROR(glEnableVertexAttribArray(location));
    MBGL_CHECK_ERROR(glVertexAttribPointer(
        location,
        count,
        static_cast<GLenum>(type),
        GL_FALSE,
        static_cast<GLsizei>(vertexSize),
        reinterpret_cast<GLvoid*>(attributeOffset + (vertexSize * vertexOffset))));
}

} // namespace gl
} // namespace mbgl

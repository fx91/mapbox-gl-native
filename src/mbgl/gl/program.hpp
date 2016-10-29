#pragma once

#include <mbgl/gl/types.hpp>
#include <mbgl/gl/object.hpp>
#include <mbgl/gl/context.hpp>

namespace mbgl {
namespace gl {

template <class Shaders, class As, class Us>
class Program {
public:
    using Attributes = As;
    using Vertex = typename Attributes::Vertex;

    using Uniforms = Us;
    using UniformValues = typename Uniforms::Values;

    Program(Context& context)
        : vertexShader(context.createShader(ShaderType::Vertex, Shaders::vertexSource)),
          fragmentShader(context.createShader(ShaderType::Fragment, Shaders::fragmentSource)),
          program(context.createProgram(vertexShader, fragmentShader)),
          attributesState(Attributes::state(program)),
          uniformsState(Uniforms::state(program)) {}

    UniqueShader vertexShader;
    UniqueShader fragmentShader;
    UniqueProgram program;

    typename Attributes::State attributesState;
    typename Uniforms::State uniformsState;
};

} // namespace gl
} // namespace mbgl

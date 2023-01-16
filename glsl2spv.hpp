#ifndef GLSL2SPV_HPP
#define GLSL2SPV_HPP

#include <vector>
#include <string>
#include <cstdint>

namespace glsl2spv{

enum class ShaderType{
    Vertex = 0,
    Geometry,
    TessellationControl,
    TessellationEvaluation,
    Fragment,
    Compute
};

using LogProc = void (*)(const char *message);

struct Includer {
    virtual std::string Include(const char* header_name)const = 0;
};

void DefaultLogger(const char *message);

bool CompileGLSL2SPV(const char* sources, size_t sources_length, ShaderType type, std::vector<std::uint32_t>& out_binary, const Includer &include, LogProc logger = DefaultLogger);

}//namespace glsl2spv

#endif//GLSL2SPV_HPP
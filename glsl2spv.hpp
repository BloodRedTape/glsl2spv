#ifndef GLSL2SPV_HPP
#define GLSL2SPV_HPP

#include <vector>
#include <cstdint>

namespace glsl2spv{

enum class ShaderType{
    Vertex = 0,
    Geometry,
    TesselationControl,
    TesselationEvaluation,
    Fragment,
    Compute
};

using LogProc = void (*)(const char *message);

void DefaultLogger(const char *message);

bool CompileGLSL2SPV(const char *sources, size_t sources_length, ShaderType type, std::vector<std::uint32_t> &out_binary, LogProc logger = DefaultLogger);

}//namespace glsl2spv

#endif//GLSL2SPV_HPP
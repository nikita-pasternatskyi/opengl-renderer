#pragma once
#include "DebugConsole.h"

namespace MP::Renderer::Debugging::DebugLog
{
    #define RENDERER_LOG(x) LOG("[RENDERER]::" << x)
    #define RENDERER_LOG_ERROR(x) LOG_ERROR("[RENDERER]::" << x)
    #define RENDERER_LOG_WARNING(x) LOG_WARNING("[RENDERER]::" << x)

    #define OPENGL_RENDERER_LOG(x) RENDERER_LOG("[OPENGL]::" << x)
    #define OPENGL_RENDERER_LOG_ERROR(x) RENDERER_LOG_ERROR("[OPENGL]::" << x)
    #define OPENGL_RENDERER_LOG_WARNING(x) RENDERER_LOG_WARNING("[OPENGL]::" << x)
}
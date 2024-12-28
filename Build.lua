workspace "OpenGL-Renderer"
    architecture "x64"
    configurations {"Debug", "Release", "Dist"}
    startproject "Renderer"

    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group ""
include "Renderer/Build-Renderer.lua"
include "DebugConsole/Build-Console.lua"
project "Renderer"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"
    postbuildcommands 
    {
        "{COPYDIR} Resources ../Binaries/" .. OutputDir .. "/%{prj.name}/Resources/",
    }

    files {"Source/**.cpp", "Source/**.hpp", "Source/**.c", "Source/**.h"}

    libdirs 
    {
        "Library/**",
        "Library/",
        "../Binaries/Intermediates" .. OutputDir .. "/DebugConsole/",
    }

    includedirs
    {
        "Include",
        "Source",
        "../DebugConsole/Source/"
    }

    links
    {
        "glfw3",
        "assimp-vc143-mt",
        "DebugConsole",
    }

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    filter "system:windows"
        systemversion "latest"
        defines "WINDOWS"
        architecture "x86_64"

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        kind "WindowedApp"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        kind "WindowedApp"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "Off"

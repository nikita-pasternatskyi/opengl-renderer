project "DebugConsole"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    files {"Source/**.cpp", "Source/**.hpp", "Source/**.c", "Source/**.h"}

    libdirs 
    {
        "Library/**"
    }

    includedirs
    {
        "Include",
        "Source"
    }

    links
    {
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

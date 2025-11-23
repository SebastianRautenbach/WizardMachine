workspace "WizardMachine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
CoreInclude = "wizm core/includes"
PlatformInclude = "wizm platform/includes"


project "WizmCore"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    location "wizm core"


    warnings "Extra"    


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")

    files
    {
        "wizm core/src/**.cpp",
        "wizm core/src/**.c",
        "wizm core/includes/**.h",
        "wizm core/includes/**.hpp"
    }

    includedirs
    {
        "wizm core/includes",
    }

    libdirs 
    {
        "wizm core/lib"
    }

    links 
    {
    }

    filter "system.windows"
        systemversion "latest"


    filter "configurations:Debug"
        runtime "Debug"
        staticruntime "On"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        staticruntime "On"
        optimize "On"




------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------


project "WizmPlatform"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    location "wizm platform"


    warnings "Extra"    


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")

    files
    {
        "wizm platform/src/**.cpp",
        "wizm platform/src/**.c",
        "wizm platform/includes/**.h",
        "wizm platform/includes/**.hpp"
    }

    includedirs
    {
        "wizm platform/includes",
        "wizm platform/includes/thirdparty",
        CoreInclude

    }

    libdirs 
    {
        "wizm platform/lib"
    }

    links 
    {
        "glfw3dll",
        "WizmCore"
    }

    filter "system.windows"
        systemversion "latest"


    filter "configurations:Debug"
        runtime "Debug"
        staticruntime "On"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        staticruntime "On"
        optimize "On"



------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------



project "WizmRender"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    location "wizm render"

    warnings "Extra"    


    targetdir ("bin/" .. outputdir .. "/%{prj.name}")

    files
    {
        "wizm render/src/**.cpp",
        "wizm render/src/**.c",
        "wizm render/includes/**.h",
        "wizm render/includes/**.hpp",
        "wizm render/includes/thirdparty/glad.c",
    }

    includedirs
    {
        "wizm render/includes",
        "wizm render/includes/thirdparty",
        CoreInclude,
        PlatformInclude,
    }

    libdirs 
    {
        "wizm render/lib"
    }

    links 
    {
        "WizmCore",
        "WizmPlatform",
        "opengl32",

    }

    filter "system.windows"
        systemversion "latest"


    filter "configurations:Debug"
        runtime "Debug"
        staticruntime "On"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        staticruntime "On"
        optimize "On"






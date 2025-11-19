workspace "WizardMachine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "WizmCore"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
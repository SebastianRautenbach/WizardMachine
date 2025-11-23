workspace "WizardMachine"
    architecture "x64"
    startproject "WizmRender"

    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-------------------------------------------------------
-- Global Include and Library Directories
-------------------------------------------------------

IncludeDir = {}
IncludeDir["Core"]     = "engine/WizmCore/includes"
IncludeDir["Platform"] = "engine/WizmPlatform/includes"
IncludeDir["Render"]   = "engine/WizmRender/includes"

IncludeDir["GLFW"]     = "vendor/glfw/include"
IncludeDir["GLAD"]     = "vendor/glad/include"
IncludeDir["KHR"]      = "vendor/KHR/include"

LibDir = {}
LibDir["Core"]         = "engine/WizmCore/lib"
LibDir["Platform"]     = "engine/WizmPlatform/lib"
LibDir["GLFW"]         = "vendor/glfw/lib"

BinDir = {}
BinDir["GLFW"]         = "vendor/glfw/bin"

-------------------------------------------------------
-- Module Creation Helper
-------------------------------------------------------

function CreateModule(name, kindType, path)
    project(name)
        kind(kindType)
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        location(path)
        targetdir("bin/" .. outputdir .. "/%{prj.name}")
        objdir("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            path .. "/src/**.cpp",
            path .. "/src/**.c",
            path .. "/includes/**.h",
            path .. "/includes/**.hpp"
        }

        includedirs {
            path .. "/includes",
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            runtime "Release"
            optimize "On"

        filter {}
end

-------------------------------------------------------
-- WIZM CORE MODULE
-------------------------------------------------------

CreateModule("WizmCore", "StaticLib", "engine/WizmCore")

includedirs {
    IncludeDir["Core"]
}

libdirs {
    LibDir["Core"]
}

-------------------------------------------------------
-- WIZM PLATFORM MODULE
-------------------------------------------------------

CreateModule("WizmPlatform", "StaticLib", "engine/WizmPlatform")

includedirs {
    IncludeDir["Platform"],
    IncludeDir["Core"],
    IncludeDir["GLFW"]
}

libdirs {
    LibDir["Platform"],
    LibDir["GLFW"]
}

links {
    "WizmCore",
    "glfw3dll"
}

-------------------------------------------------------
-- WIZM RENDER (Executable)
-------------------------------------------------------

project "WizmRender"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    location "engine/WizmRender"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "engine/WizmRender/src/**.cpp",
        "engine/WizmRender/includes/**.h",
        "engine/WizmRender/includes/**.hpp",
        "vendor/glad/src/glad.c"
    }

    includedirs {
        IncludeDir["Render"],
        IncludeDir["Core"],
        IncludeDir["Platform"],
        IncludeDir["GLFW"],
        IncludeDir["GLAD"],
        IncludeDir["KHR"],
    }

    libdirs { 
        LibDir["GLFW"]
    }

    links {
        "WizmCore",
        "WizmPlatform",
        "opengl32"
    }

--    postbuildcommands {
--        "{COPYFILE} /vendor/glfw/bin/glfw3.dll ../../../bin/Debug-windows-x86_64/WizmRender"
--    }


    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"



--ok, err = os.copyfile("/vendor/glfw/bin/glfw3.dll", "%{cfg.targetdir")


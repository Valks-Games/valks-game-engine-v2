-- Based from https://github.com/TheCherno/Hazel/blob/749b66558e1295921ceedcef02866b2c43480e75/premake5.lua

workspace "ValkEngine"
	architecture "x86_64"
	startproject "engine"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "vendor/glfw"
include "vendor/glad"

project "engine"
	location "engine"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"engine/src/**.h",
		"engine/src/**.cpp",
	}

	includedirs
	{
		"vendor/glad/include",
		"vendor/glfw/include",
		"vendor/glm",
	}

	links 
	{ 
		"glfw",
		"glad",
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}
		links{"opengl32.lib"}
	filter "system:linux"
		systemversion "latest"
		links{"pthread","dl","GL","GLU","X11"}

	filter "configurations:Debug"
		defines "VE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HVE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VE_DIST"
		runtime "Release"
		optimize "on"
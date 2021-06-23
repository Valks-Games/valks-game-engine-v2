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

project "Engine"
	location "engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"engine/src/**.h",
		"engine/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"vendor/glad/include",
		"vendor/glfw/include",
		"vendor/glm",
		"vendor/spdlog/include"
	}

	links 
	{ 
		"glfw",
		"glad",
	}

	defines
	{
		"GLFW_INCLUDE_NONE"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"VE_WIN"
		}
		
		links { "opengl32.lib" }
		
		disablewarnings -- Suppress spdlog's annoying warnings
		{ 
			"26451",
			"26812",
			"26498",
			"26495"
		} 
		
	filter "system:linux"
		systemversion "latest"
		
		defines
		{
			"VE_LINUX"
		}
		
		links { "pthread", "dl", "GL", "GLU", "X11" }

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

project "Sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"vendor/spdlog/include",
		"Valk/src"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "VE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VE_DIST"
		runtime "Release"
		optimize "on"
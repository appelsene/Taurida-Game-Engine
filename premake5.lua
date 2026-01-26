workspace "Taurida"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Taurida/vendor/GLFW/include"

include "Taurida/vendor/GLFW"

project "GLFW"
	staticruntime "on"
	buildoptions "/utf-8"

project "Taurida"
	location "Taurida"
	kind "SharedLib"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "trdpch.h"
	pchsource "Taurida/src/trdpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	buildoptions "/utf-8"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"TRD_PLATFORM_WINDOWS",
			"TRD_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TRD_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TRD_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TRD_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Taurida/vendor/spdlog/include",
		"Taurida/src",
		"Taurida/vendor"
	}

	links 
	{
		"Taurida"
	}

	buildoptions "/utf-8"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"TRD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TRD_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "TRD_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "TRD_DIST"
		runtime "Release"
		optimize "On"
workspace "game-of-life"
	configurations { "Debug", "Release" }
	platforms { "x86", "x64" }

	SDLdir = "vendor/SDL2/"

	project "game-of-life"
		language "C++"
		targetdir "bin/%{cfg.architecture}/%{cfg.buildcfg}"
		
		files { "**.cpp", "**.h" }
		
		links { 
			"SDL2",
			"SDL2main",
			"SDL2_ttf"
		}
		
		filter "configurations:Debug"
			kind "ConsoleApp"
			defines { "DEBUG" }
			symbols "On"
			
		filter "configurations:Release"
			kind "WindowedApp"
			defines { "NDEBUG" }
			optimize "On"
			
		filter "action:vs*"
			systemversion "latest"
			includedirs (SDLdir .. "msvc/include")
			defines "_MSVC_"
			
		filter {"action:vs*", "platforms:x86"}
			libdirs (SDLdir .. "msvc/lib/x86")
			
		filter {"action:vs*", "platforms:x64"}
			libdirs (SDLdir .. "msvc/lib/x64")
			
		filter {"system:windows", "action:gmake2", "platforms:x86"}
			includedirs (SDLdir .. "mingw/i686-w64-mingw32/include/SDL2")
			libdirs (SDLdir .. "mingw/i686-w64-mingw32/lib")
			
		filter {"system:windows", "action:gmake2", "platforms:x64"}
			includedirs (SDLdir .. "mingw/x86_64-w64-mingw32/include/SDL2")
			libdirs (SDLdir .. "mingw/x86_64-w64-mingw32/lib")
		
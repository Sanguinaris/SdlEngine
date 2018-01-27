cmake_minimum_required(VERSION 3.8)
project(SDLEngine VERSION 0.0.1)

option(ENABLE_TESTING "Builds the test framework" OFF)

if(ENABLE_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()


find_library(libsdl NAMES libSDL2)
find_library(libsdl_ttf NAMES libSDL2_ttf)
find_library(libsdl_mixer NAMES libSDL2_mixer)
find_library(libsdl_image NAMES libSDL2_image)

set(LIB_HEADERS	Entities/BaseEntity.h Entities/EntityManager.h
				Entities/Characteristics/Collider.h Entities/Characteristics/Physiks.h Entities/Characteristics/Player.h Entities/Characteristics/Trigger.h
				GameLogics/CollisionManager.h GameLogics/GravityManager.h
				GameLogics/InputManager/InputManager.h GameLogics/InputManager/Key.h
				General/Engine.h General/Logger.h General/OptionManager.h
				Helpers/LoaderHelper.h
				Map/MapManager.h)

set(LIB_UNITS	Entities/Characteristics/Collider.cpp
				GameLogics/InputManager/InputManager.cpp
				General/Engine.cpp General/Logger.cpp General/OptionManager.cpp
				Map/MapManager.cpp)

add_library(SDLEngine ${LIB_UNITS} ${LIB_HEADERS})
add_executable(SDLEngineRunner MainEntry.cpp ${LIB_HEADERS})
add_dependencies(SDLEngineRunner SDLEngine)
target_link_libraries(SDLEngine ${libsdl} ${libsdl_ttf})
target_link_libraries(SDLEngineRunner SDLEngine)

set_target_properties(SDLEngineRunner SDLEngine PROPERTIES
	C_STANDARD 11
	C_STANDARD_REQUIRED YES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	FOLDER Engine)

set_target_properties(SDLEngine PROPERTIES PUBLIC_HEADER "${LIB_HEADERS}")
install(TARGETS SDLEngine RUNTIME DESTINATION bin ARCHIVE DESTINATION lib PUBLIC_HEADER DESTINATION include)

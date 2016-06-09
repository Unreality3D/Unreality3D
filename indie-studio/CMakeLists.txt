cmake_minimum_required (VERSION 2.8)

project (Test-Ogre)

if (NOT ANDROID)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
endif (NOT ANDROID)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../include")
set(INDIE_LIB_BUILD "${CMAKE_SOURCE_DIR}/lib")
set(EXTERN_LIB_DIR "${CMAKE_SOURCE_DIR}/../lib")
set(SCRIPT_DIR "${CMAKE_SOURCE_DIR}/script")

include_directories("${INCLUDE_DIR}/Ogre"
		    "${INCLUDE_DIR}/OIS"
		    "${INCLUDE_DIR}/"
		    "include/Collider"
		    "include/"
		    "${SCRIPT_DIR}/include"
		    )

if(NOT ${CMAKE_SOURCE_DIR}/lib)
  file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
endif()

if (UNIX AND NOT ANDROID)
  include(${CMAKE_SOURCE_DIR}/cmake/SystemLinux.cmake)
elseif (ANDROID)
  include(${CMAKE_SOURCE_DIR}/cmake/SystemAndroid.cmake)
else ()
  include(${CMAKE_SOURCE_DIR}/cmake/SystemWindows.cmake)
endif (UNIX AND NOT ANDROID)

include(${CMAKE_SOURCE_DIR}/source/LibraryLoader/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/MapGenerator/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/OgreUtilities/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/OgreObject/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/Sound/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/InputManager/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/Gui/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/IndieStudio/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/Collider/CMakeLists.txt)
include(${CMAKE_SOURCE_DIR}/source/Network/CMakeLists.txt)

include(${SCRIPT_DIR}/CMakeLists.txt)

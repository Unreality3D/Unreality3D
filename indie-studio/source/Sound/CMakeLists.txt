cmake_minimum_required (VERSION 2.8)

project (Sound)

set(SOUND-DIR "${CMAKE_SOURCE_DIR}/source/Sound")

set(SOUND-UTIL
	"${SOUND-DIR}/Music.cpp"
	"${SOUND-DIR}/PlayList.cpp"
	)

add_library(Sound SHARED ${SOUND-UTIL})

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    "-lsfml-system"
    "-lsfml-audio"
    "-lOgreMain"
    "-lboost_system"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lOgreMainStatic"
    "-lboost_system-gcc-mt-1_53"
    "-lsfml-system"
    "-lsfml-audio"
    )
endif (ANDROID)

target_link_libraries(Sound ${INDIE-LIB})
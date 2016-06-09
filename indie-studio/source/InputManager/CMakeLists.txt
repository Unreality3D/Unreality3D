cmake_minimum_required (VERSION 2.8)

project (Ogre-utilities)

set(INPUT-MANAGER-DIR "${CMAKE_SOURCE_DIR}/source/InputManager")

set(INPUT-MANAGER
	"${INPUT-MANAGER-DIR}/InputManager.cpp"
	"${INPUT-MANAGER-DIR}/MListener.cpp"
	"${INPUT-MANAGER-DIR}/KListener.cpp"
	)

add_library(InputManager SHARED ${INPUT-MANAGER})

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    "-lOgreMain"
    "-lboost_system"
    "-lOIS"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lOgreMainStatic"
    "-lboost_system-gcc-mt-1_53"
    "-lOIS"
    )
endif (ANDROID)

target_link_libraries(InputManager ${INDIE-LIB})

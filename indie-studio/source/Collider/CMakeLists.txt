cmake_minimum_required (VERSION 2.8)

project (Collider)

set(COLLIDER-DIR "${CMAKE_SOURCE_DIR}/source/Collider")

set(COLLIDER-UTIL
	"${COLLIDER-DIR}/CollisionTools.cpp"
	"${COLLIDER-DIR}/Collider.cpp"
	)

add_library(Collider SHARED ${COLLIDER-UTIL})

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    "-lOgreMain"
    "-lboost_system"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lOgreMainStatic"
    "-lboost_system-gcc-mt-1_53"
    )
endif (ANDROID)

target_link_libraries(Collider ${INDIE-LIB})

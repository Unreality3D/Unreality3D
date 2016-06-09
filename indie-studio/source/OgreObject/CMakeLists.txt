cmake_minimum_required (VERSION 2.8)

project (Ogre-utilities)

set(OGRE-OBJ-DIR "${CMAKE_SOURCE_DIR}/source/OgreObject")

set(OGRE-OBJ
	"${OGRE-OBJ-DIR}/RenderObject.cpp"
	"${OGRE-OBJ-DIR}/Mesh.cpp"
	"${OGRE-OBJ-DIR}/Empty.cpp"
	)

add_library(OgreObject SHARED ${OGRE-OBJ})

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

target_link_libraries(OgreObject ${INDIE-LIB})

cmake_minimum_required (VERSION 2.8)

project (Ogre-utilities)

set(OGRE-UTIL-DIR "${CMAKE_SOURCE_DIR}/source/OgreUtilities")

set(OGRE-UTIL
	"${OGRE-UTIL-DIR}/InitOgre.cpp"
	"${OGRE-UTIL-DIR}/RenderSystem.cpp"
	"${OGRE-UTIL-DIR}/RenderWindow.cpp"
	"${OGRE-UTIL-DIR}/SceneManager.cpp"
	"${OGRE-UTIL-DIR}/Viewport.cpp"
	"${OGRE-UTIL-DIR}/OgreMap.cpp"
	"${OGRE-UTIL-DIR}/Camera.cpp"
	)

add_library(OgreUtilities SHARED ${OGRE-UTIL})

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
    "-lboost_thread-gcc-mt-1_53"
    "-lcpufeature"
    "-llog"
    )
endif (ANDROID)

target_link_libraries(OgreUtilities ${INDIE-LIB})

cmake_minimum_required (VERSION 2.8)

project (Indie-Studio)

set(INDIE-STUDIO-DIR "${CMAKE_SOURCE_DIR}/source/IndieStudio")
include("${CMAKE_SOURCE_DIR}/source/Tools/CMakeLists.txt")

set(INDIE-STUDIO
  "${INDIE-STUDIO-DIR}/GameManager.cpp"
  "${INDIE-STUDIO-DIR}/GameObject.cpp"
  "${INDIE-STUDIO-DIR}/GameObjectManager.cpp"
  "${INDIE-STUDIO-DIR}/Stats.cpp"
  "${INDIE-STUDIO-DIR}/MapDisplayer.cpp"
  "${INDIE-STUDIO-DIR}/IndieParser.cpp"
  "${INDIE-STUDIO-DIR}/PrefabCreator.cpp"
  "${INDIE-STUDIO-DIR}/Stats.cpp"
  "${INDIE-STUDIO-DIR}/FrameListener.cpp"
  )

addTools(INDIE-STUDIO)

add_library(IndieStudio SHARED ${INDIE-STUDIO})

add_dependencies(IndieStudio
  OgreUtilities
  OgreObject
  InputManager
  Sound
#  Gui
  MapGenerator
  LibraryLoader
  Network
  )

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    "-lOgreMain"
    "-lboost_system"
    )

  set(INTERN-LIB
     "-lOgreUtilities"
     "-lOgreObject"
     "-lInputManager"
     "-lSound"
     "-lMapGenerator"
     "-lLibraryLoader"
     "-lNetwork"
#     "-lGui"
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

  set(INTERN-LIB
     "-lOgreUtilities"
     "-lOgreObject"
     "-lInputManager"
     "-lSound"
     "-lMapGenerator"
#     "-lGui"
    )
endif (ANDROID)


target_link_libraries(IndieStudio
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

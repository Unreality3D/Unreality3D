cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

link_directories("${EXTERN_LIB_DIR}/Ogre"
  "${EXTERN_LIB_DIR}/OIS"
  "${EXTERN_LIB_DIR}/SFML"
  "${EXTERN_LIB_DIR}/Cegui"
  "${INDIE_LIB_BUILD}"
  "${CMAKE_SOURCE_DIR}/script/lib"
  )

set(OGRE-MAIN
  "${CMAKE_SOURCE_DIR}/source/main.cpp"
  )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../)

add_executable(Unreality ${OGRE-MAIN})

add_dependencies(Unreality IndieStudio)

set(INDIE-LIB
  "-lOgreMain"
  "-lboost_system"
  )

set(INTERN-LIB
  "-lIndieStudio"
  "-lOgreUtilities"
  "-lOgreObject"
  "-lInputManager"
  "-lSound"
  "-lGui"
  "-lCollider"
  )

target_link_libraries(Unreality
  ${INDIE-LIB}
  ${INTERN-LIB}
  )
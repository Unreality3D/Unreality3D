cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

set(SYSROOT "/home/gandoulf/my-android-toolchain/sysroot/usr/lib")
link_directories("${SYSROOT}" "${INDIE_LIB_BUILD}")

set(OGRE-MAIN
  #"${CMAKE_SOURCE_DIR}/source/main.cpp"                                                        
  "${CMAKE_SOURCE_DIR}/source/appDemarrage.cpp"
  #"${CMAKE_SOURCE_DIR}/source/GameObject.cpp"                                                  
  )

add_library(ogre-test SHARED ${OGRE-MAIN})

set(INDIE-LIB
  "-lOgreMainStatic"
  "-lboost_system-gcc-mt-1_53"
  "-llog"
  )

set(INTERN-LIB
  "-lOgreUtilities"
  "-lOgreObject"
  "-lInputManager"
  "-lSound"
  )
target_link_libraries(ogre-test
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

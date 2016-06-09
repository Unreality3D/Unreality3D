cmake_minimum_required (VERSION 2.8)

project (LibraryLoader)

set(LIBRARY-LOADER-DIR "${CMAKE_SOURCE_DIR}/source/LibraryLoader")

set(LIBRARY-LOADER
  "${LIBRARY-LOADER-DIR}/LibraryLoader.cpp"
  )

add_library(LibraryLoader SHARED ${LIBRARY-LOADER})

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    "-ldl"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-ldl"
    )
endif (ANDROID)

target_link_libraries(LibraryLoader ${INDIE-LIB})

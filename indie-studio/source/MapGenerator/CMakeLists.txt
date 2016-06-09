cmake_minimum_required (VERSION 2.8)

project (MapGenerator)

set(MAP-GENERATOR-DIR "${CMAKE_SOURCE_DIR}/source/MapGenerator")

set(MAP-GENERATOR
	"${MAP-GENERATOR-DIR}/MapGenerator.cpp"
	"${MAP-GENERATOR-DIR}/MgUtils.cpp"
	)

add_library(MapGenerator SHARED ${MAP-GENERATOR})

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    )
endif (ANDROID)

target_link_libraries(MapGenerator ${INDIE-LIB})

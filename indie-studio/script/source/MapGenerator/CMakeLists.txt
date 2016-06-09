cmake_minimum_required (VERSION 2.8)

project (SMapGenerator-Script)

set(SMAPGENERATOR-DIR "${SCRIPT_SOURCE_DIR}/MapGenerator")

set(SMAPGENERATOR
  "${SMAPGENERATOR-DIR}/SMapGenerator.cpp"
  )

add_library(SMapGenerator SHARED ${SMAPGENERATOR})

add_dependencies(SMapGenerator IndieStudio MapGenerator)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )
  
  set(INTERN-LIB
    "-lIndieStudio"
    "-lMapGenerator"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )
  
  set(INTERN-LIB
    "-lIndieStudio"
    "-lMapGenerator"
    )
endif (ANDROID)

target_link_libraries(SMapGenerator
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

set_target_properties(SMapGenerator PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT
)
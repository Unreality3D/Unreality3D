cmake_minimum_required (VERSION 2.8)

project (Default-Script)

set(DEFAULT-DIR "${SCRIPT_SOURCE_DIR}/default")

set(DEFAULT
  "${DEFAULT-DIR}/Default.cpp"
  )

add_library(Default SHARED ${DEFAULT})

add_dependencies(Default IndieStudio)
set_target_properties(Default PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_DEFAULT
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )

  set(INTERN-LIB
    )
endif (ANDROID)

target_link_libraries(Default
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

cmake_minimum_required (VERSION 2.8)

project (Stairs-Script)

set(STAIRS-DIR "${SCRIPT_SOURCE_DIR}/Stairs")

set(STAIRS
  "${STAIRS-DIR}/Stairs.cpp"
  )

add_library(Stairs SHARED ${STAIRS})

add_dependencies(Stairs IndieStudio Gauntlet)
set_target_properties(Stairs PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_STAIRS
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    "-lGauntlet"
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

target_link_libraries(Stairs
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

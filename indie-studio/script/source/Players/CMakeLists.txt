cmake_minimum_required (VERSION 2.8)

project (Players-Script)

set(PLAYERS-DIR "${SCRIPT_SOURCE_DIR}/Players")

set(PLAYERS
  "${PLAYERS-DIR}/Players.cpp"
  )

add_library(Players SHARED ${PLAYERS})

add_dependencies(Players IndieStudio)
set_target_properties(Players PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_PLAYERS
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

target_link_libraries(Players
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

cmake_minimum_required (VERSION 2.8)

project (BomberMan-Script)

set(BOMBERMAN-DIR "${SCRIPT_SOURCE_DIR}/BomberMan")

set(BOMBERMAN
  "${BOMBERMAN-DIR}/BomberMan.cpp"
  )

add_library(BomberMan SHARED ${BOMBERMAN})

add_dependencies(BomberMan IndieStudio Players)
set_target_properties(BomberMan PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_BOMBERMAN
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    "-lPlayers"
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

target_link_libraries(BomberMan
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

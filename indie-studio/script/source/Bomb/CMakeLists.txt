cmake_minimum_required (VERSION 2.8)

project (Bomb-Script)

set(BOMB-DIR "${SCRIPT_SOURCE_DIR}/Bomb")

set(BOMB
  "${BOMB-DIR}/Bomb.cpp"
  )

add_library(Bomb SHARED ${BOMB})

add_dependencies(Bomb IndieStudio Deflagration)
set_target_properties(Bomb PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_BOMB
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    "-lDeflagration"
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

target_link_libraries(Bomb
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

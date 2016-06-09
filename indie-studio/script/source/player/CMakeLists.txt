cmake_minimum_required (VERSION 2.8)

project (Player-Script)

set(PLAYER-DIR "${SCRIPT_SOURCE_DIR}/player")

set(PLAYER
  "${PLAYER-DIR}/Player.cpp"
  )

add_library(Player SHARED ${PLAYER})

add_dependencies(Player IndieStudio RangeAutoAttack Gui)
set_target_properties(Player PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_PLAYER
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    "-lRangeAutoAttack"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )

  set(INTERN-LIB
    "-lRangeAutoAttack"
    )
endif (ANDROID)

target_link_libraries(Player
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

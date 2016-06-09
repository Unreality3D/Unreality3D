cmake_minimum_required (VERSION 2.8)

project (Archer-Script)

set(ARCHER-DIR "${SCRIPT_SOURCE_DIR}/archer")

set(ARCHER
  "${ARCHER-DIR}/Archer.cpp"
  )

add_library(Archer SHARED ${ARCHER})

add_dependencies(Archer IndieStudio RangeAutoAttack Player)
set_target_properties(Archer PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_ARCHER
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    "-lRangeAutoAttack"
    "-lPlayer"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )

  set(INTERN-LIB
    "-lRangeAutoAttack"
    "-lPlayer"
    )
endif (ANDROID)

target_link_libraries(Archer
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

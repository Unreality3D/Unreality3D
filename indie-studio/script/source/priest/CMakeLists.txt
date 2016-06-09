cmake_minimum_required (VERSION 2.8)

project (Priest-Script)

set(PRIEST-DIR "${SCRIPT_SOURCE_DIR}/priest")

set(PRIEST
  "${PRIEST-DIR}/Priest.cpp"
  )

add_library(Priest SHARED ${PRIEST})

add_dependencies(Priest IndieStudio RangeAutoAttack Player)
set_target_properties(Priest PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_PRIEST
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

target_link_libraries(Priest
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

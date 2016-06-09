cmake_minimum_required (VERSION 2.8)

project (RangeAutoAttack-Script)

set(RANGEAUTOATTACK-DIR "${SCRIPT_SOURCE_DIR}/RangeAutoAttack")

set(RANGEAUTOATTACK
  "${RANGEAUTOATTACK-DIR}/RangeAutoAttack.cpp"
  )

add_library(RangeAutoAttack SHARED ${RANGEAUTOATTACK})

add_dependencies(RangeAutoAttack IndieStudio)
set_target_properties(RangeAutoAttack PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_RANGEAUTOATTACK
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

target_link_libraries(RangeAutoAttack
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

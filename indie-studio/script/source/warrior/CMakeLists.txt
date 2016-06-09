cmake_minimum_required (VERSION 2.8)

project (Warrior-Script)

set(WARRIOR-DIR "${SCRIPT_SOURCE_DIR}/warrior")

set(WARRIOR
  "${WARRIOR-DIR}/Warrior.cpp"
  )

add_library(Warrior SHARED ${WARRIOR})

add_dependencies(Warrior IndieStudio RangeAutoAttack Player)
set_target_properties(Warrior PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_WARRIOR
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

target_link_libraries(Warrior
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

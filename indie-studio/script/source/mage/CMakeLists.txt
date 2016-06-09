cmake_minimum_required (VERSION 2.8)

project (Mage-Script)

set(MAGE-DIR "${SCRIPT_SOURCE_DIR}/mage")

set(MAGE
  "${MAGE-DIR}/Mage.cpp"
  )

add_library(Mage SHARED ${MAGE})

add_dependencies(Mage IndieStudio RangeAutoAttack Player)
set_target_properties(Mage PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_MAGE
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

target_link_libraries(Mage
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

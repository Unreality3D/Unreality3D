cmake_minimum_required (VERSION 2.8)

project (Gobelin-Script)

set(GOBELIN-DIR "${SCRIPT_SOURCE_DIR}/gobelin")

set(GOBELIN
  "${GOBELIN-DIR}/Gobelin.cpp"
  )

add_library(Gobelin SHARED ${GOBELIN})

add_dependencies(Gobelin IndieStudio SMapGenerator Player RangeAutoAttack)
set_target_properties(Gobelin PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_GOBELIN
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
#    "-lIndieStudio"
    "-lSMapGenerator"
    "-lPlayer"
    "-lRangeAutoAttack"
#    "-lArcher"
#    "-lMage"
#    "-lPriest"
#    "-lWarrior"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )

  set(INTERN-LIB
    #    "-lIndieStudio"
    "-lSMapGenerator"
    "-lPlayer"
    "-lRangeAutoAttack"
    #    "-lArcher"
    #    "-lMage"
    #    "-lPriest"
    #    "-lWarrior"
    )
endif (ANDROID)

target_link_libraries(Gobelin
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

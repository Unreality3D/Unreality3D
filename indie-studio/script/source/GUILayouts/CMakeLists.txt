cmake_minimum_required (VERSION 2.8)

project (GUILayouts-Script)

set(GUILAYOUTS-DIR "${SCRIPT_SOURCE_DIR}/GUILayouts")

set(GUILAYOUTS
  "${GUILAYOUTS-DIR}/GUILayouts.cpp"
  "${GUILAYOUTS-DIR}/MainMenu.cpp"
  "${GUILAYOUTS-DIR}/Functors.cpp"
  "${GUILAYOUTS-DIR}/EscMenu.cpp"
  "${GUILAYOUTS-DIR}/ClassSelectionMenu.cpp"
  "${GUILAYOUTS-DIR}/InGameMenu.cpp"  
  )

add_library(GUILayouts SHARED ${GUILAYOUTS})

add_dependencies(GUILayouts IndieStudio Gui)
set_target_properties(GUILayouts PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_GUILAYOUTS
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
  "-lGui"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )

  set(INTERN-LIB
  "-lGui"
    )
endif (ANDROID)

target_link_libraries(GUILayouts
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

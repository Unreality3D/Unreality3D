cmake_minimum_required (VERSION 2.8)

project (Default-Script)

set(GAUNTLET-DIR "${SCRIPT_SOURCE_DIR}/Gauntlet")

set(GAUNTLET
  "${GAUNTLET-DIR}/Gauntlet.cpp"
  )

add_library(Gauntlet SHARED ${GAUNTLET})

add_dependencies(Gauntlet IndieStudio Gui SMapGenerator Player GUILayouts)
set_target_properties(Gauntlet PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_GAUNTLET
)

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    )

  set(INTERN-LIB
    "-lPlayer"
    "-lSMapGenerator"
    "-lGUILayouts"
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    "-lcpufeature"
    "-llog"
    )

  set(INTERN-LIB
    "-lPlayer"
    "-lSMapGenerator"
    "-lGUILayouts"
    )
endif (ANDROID)

target_link_libraries(Gauntlet
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

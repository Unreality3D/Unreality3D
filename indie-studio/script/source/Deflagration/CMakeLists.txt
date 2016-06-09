cmake_minimum_required (VERSION 2.8)

project (Deflagration-Script)

set(DEFLAGRATION-DIR "${SCRIPT_SOURCE_DIR}/Deflagration")

set(DEFLAGRATION
  "${DEFLAGRATION-DIR}/Deflagration.cpp"
  )

add_library(Deflagration SHARED ${DEFLAGRATION})

add_dependencies(Deflagration IndieStudio)
set_target_properties(Deflagration PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_LIB_DIR}
  COMPILE_FLAGS
  -DSCRIPT_DEFLAGRATION
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

target_link_libraries(Deflagration
  ${INDIE-LIB}
  ${INTERN-LIB}
  )

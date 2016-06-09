cmake_minimum_required (VERSION 2.8)

set(TOOLS-DIR "${CMAKE_SOURCE_DIR}/source/Tools")

function(addTools arg1)
  set(${arg1}
    "${${arg1}}"
    "${TOOLS-DIR}/Thread.cpp"
    "${TOOLS-DIR}/chrono.cpp"
    PARENT_SCOPE
    )
endfunction(addTools)
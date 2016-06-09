cmake_minimum_required (VERSION 2.8)

project (Network)

set(NETWORK-DIR "${CMAKE_SOURCE_DIR}/source/Network")

set(NETWORK
  "${NETWORK-DIR}/NetManager.cpp"
  "${NETWORK-DIR}/Broker.cpp"
  "${NETWORK-DIR}/protocol/Deserializer.cpp"
  "${NETWORK-DIR}/protocol/Serializer.cpp"
  "${NETWORK-DIR}/sockets/Client.cpp"
  "${NETWORK-DIR}/sockets/Server.cpp"
  )

add_library(Network SHARED ${NETWORK})

if (UNIX AND NOT ANDROID)
  set(INDIE-LIB
    -lpthread
    )
endif (UNIX AND NOT ANDROID)

if (ANDROID)
  set(INDIE-LIB
    )
endif (ANDROID)

target_link_libraries(Network ${INDIE-LIB})

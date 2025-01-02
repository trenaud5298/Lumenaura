
file(GLOB_RECURSE LUMENAURA_DEMO_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE LUMENAURA_DEMO_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cu")
message(STATUS "Cmake Current Source Director For Lumenaur-Demo: ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(Lumenaura_Demo)

target_link_libraries(Lumenaura_Demo
    PRIVATE Lumenaura_Core
)

target_include_directories(Lumenaura_Demo
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_sources(Lumenaura_Demo
    PRIVATE ${LUMENAURA_DEMO_SRC_FILES}
)

source_group("Header Files" FILES ${LUMENAURA_DEMO_HEADER_FILES})
source_group("Source Files" FILES ${LUMENAURA_DEMO_SRC_FILES})


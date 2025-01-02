#Subdirectory Is Fully Able To Be Built As A Standalone Project
#And Can Be Reused In Other Projects If Desired. Other Sub-Directories
#Are Built Off Of This Core Library

cmake_minimum_required(VERSION 3.20)
project(Lumenaura-Core CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##These Are The Publically Accesible Header Files That Provide The Interface For Interacting
##With The Library And Will Contain Only C++ .h Header Files
file(GLOB_RECURSE LUMENAURA_CORE_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

##These Are The Internal Header Files That Are Not Mean To Be Exposed To The User Of This
##Library And Contain Both C++ .h Header Files And CUDA .cuh Header Files
file(GLOB_RECURSE LUMENAURA_CORE_INTERNAL_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include_internal/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/include_internal/*.cuh")

##These Are The Source Files To Be Compiled For The Library
file(GLOB_RECURSE LUMENAURA_CORE_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cu")
message(STATUS "Cmake Current Source Director For Lumenaur-Core: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(Lumenaura_Core STATIC)

target_include_directories(Lumenaura_Core
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include_internal"
)

target_sources(Lumenaura_Core
    PRIVATE ${LUMENAURA_CORE_SRC_FILES}
)

target_compile_definitions(Lumenaura_Core
    PRIVATE $<IF:$<CONFIG:Debug>,ENABLE_LOGGING,>
)

source_group("Header Files" FILES ${LUMENAURA_CORE_HEADER_FILES})
source_group("Internal Header Files" FILES ${LUMENAURA_CORE_INTERNAL_HEADER_FILES})
source_group("Source Files" FILES ${LUMENAURA_CORE_SRC_FILES})


##Additional CUDA Configurations
set(CUDA_ARCHITECTURES 75)
set_target_properties(Lumenaura_Core PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
    CUDA_RESOLVE_DEVICE_SYMBOLS ON
    POSITION_INDEPENDENT_CODE ON
)

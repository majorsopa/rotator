cmake_minimum_required(VERSION 3.23)
project(rotator)

set(CMAKE_CXX_STANDARD 23)

set(CSVPARSER_DIR ${CMAKE_SOURCE_DIR}/external/lib/csvparser)
if(NOT EXISTS ${CSVPARSER_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/vincentlaucsb/csv-parser.git ${CSVPARSER_DIR}
    )
endif()

add_subdirectory(${CSVPARSER_DIR})
include_directories(${CSVPARSER_DIR}/include)

add_executable(rotator main.cpp RotationInfo.cpp RotationInfo.h textures/Texture.h TextureFinder.cpp TextureFinder.h verifier.h textures/TextureType.h textures/Texture.cpp)

target_link_libraries(rotator csv)

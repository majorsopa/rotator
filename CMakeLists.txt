cmake_minimum_required(VERSION 3.23)
project(rotator LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 23)
set(SRC src/main.cpp src/RotationInfo.cpp src/RotationInfo.h src/Texture.h src/TextureFinder.cpp src/TextureFinder.h src/verifier.h src/TextureType.h src/Texture.cpp)
set(CUDA_SRC src/texture_getter.cu)



set(CSVPARSER_DIR ${CMAKE_SOURCE_DIR}/external/lib/csvparser)
if(NOT EXISTS ${CSVPARSER_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/vincentlaucsb/csv-parser.git ${CSVPARSER_DIR}
    )
endif()


add_subdirectory(${CSVPARSER_DIR})
include_directories(${CSVPARSER_DIR}/include)

add_executable(rotator ${SRC} ${CUDA_SRC})

set_target_properties(rotator PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

target_link_libraries(rotator csv)

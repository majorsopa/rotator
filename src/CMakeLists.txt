cmake_minimum_required(VERSION 3.23)
project(rotator)

set(CMAKE_CXX_STANDARD 23)
set(SRC main.cpp RotationInfo.cpp RotationInfo.h textures/Texture.h TextureFinder.cpp TextureFinder.h verifier.h textures/TextureType.h textures/Texture.cpp)
set(CUDA_SRC texture_getter.cu)

set(CSVPARSER_DIR ${CMAKE_SOURCE_DIR}/external/lib/csvparser)
if(NOT EXISTS ${CSVPARSER_DIR})
    find_package(Git REQUIRED)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} clone https://github.com/vincentlaucsb/csv-parser.git ${CSVPARSER_DIR}
    )
endif()

find_package(CUDA REQUIRED)
if(CUDA_FOUND)
    include_directories(${CUDA_INCLUDE_DIRS})
    SET(ALL_CUDA_LIBS ${CUDA_LIBRARIES} ${CUDA_cusparse_LIBRARY} ${CUDA_cublas_LIBRARY})
    SET(LIBS ${LIBS} ${ALL_CUDA_LIBS})
    message(STATUS "CUDA_LIBRARIES: ${CUDA_INCLUDE_DIRS} ${ALL_CUDA_LIBS}")
    set(CUDA_PROPAGATE_HOST_FLAGS ON)
    set(CUDA_SEPARABLE_COMPILATION OFF)
    list( APPEND CUDA_NVCC_FLAGS -gencode=arch=compute_50,code=compute_50 )
    list( APPEND CUDA_NVCC_FLAGS -gencode=arch=compute_52,code=sm_52 )

    CUDA_ADD_LIBRARY(my_cuda_lib ${CUDA_SRC} STATIC)
    SET(LIBS ${LIBS} ${my_cuda_lib})
endif()

add_subdirectory(${CSVPARSER_DIR})
include_directories(${CSVPARSER_DIR}/include)

add_executable(rotator ${SRC})

target_link_libraries(rotator csv)

cmake_minimum_required(VERSION 3.23)
project(rotator)

set(CMAKE_CXX_STANDARD 23)

add_executable(rotator main.cpp RotationInfo.cpp RotationInfo.h textures/Texture.h TextureFinder.cpp TextureFinder.h verifier.h textures/TextureType.h textures/Texture.cpp)

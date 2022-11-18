#include <vector>
#include <iostream>
#include "Texture.h"
#include "RotationInfo.h"
#include "texture_getter.cuh"


__global__ void texture_getter(
        Texture * texture_provider,
        std::vector<RotationInfo> * tops_and_bottoms,
        std::vector<RotationInfo> * sides,
        int * start_x,
        int * end_x,
        int * start_y,
        int * end_y,
        int * start_z,
        int * end_z
        ) {

    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    int z = blockIdx.z * blockDim.z + threadIdx.z;

    if (x < *start_x || x > *end_x || y < *start_y || y > *end_y || z < *start_z || z > *end_z) {
        return;
    }



}

void run_texture_getter(Texture texture_provider, std::vector<RotationInfo> tops_and_bottoms, std::vector<RotationInfo> sides, int start_x, int end_x, int start_y, int end_y, int start_z, int end_z) {
    const int total_x = end_x - start_x;

    texture_getter<<<1, 64>>>(&texture_provider, &tops_and_bottoms, &sides, &start_x, &end_x, &start_y, &end_y, &start_z, &end_z);
}

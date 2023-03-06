#include <iostream>
#include "TextureFinder.h"


TextureFinder::TextureFinder(const std::pair<std::vector<RotationInfo>, std::vector<RotationInfo>>& rotation_info, int start_x, int end_x, int start_y, int end_y, int start_z, int end_z, Texture * texture_provider)
{
    this->start_x = start_x;
    this->end_x = end_x;
    this->start_y = start_y;
    this->end_y = end_y;
    this->start_z = start_z;
    this->end_z = end_z;
    this->texture_provider = texture_provider;

    this->tops_and_bottoms = rotation_info.first;
    this->sides = rotation_info.second;
}

TextureFinder::~TextureFinder() {
    delete this->texture_provider;
}

void TextureFinder::run() {
    // todo: add a elapsed time counter

    if (tops_and_bottoms.size() + sides.size() == 0) {
        std::cout << "no rotations entered" << std::endl;
        return;
    }

    int total_x = end_x - start_x;
    if (total_x < 0) total_x *= -1;
    int total_y = end_y - start_y;
    if (total_y < 0) total_y *= -1;
    int total_z = end_z - start_z;
    if (total_z < 0) total_z *= -1;

    
    for (int x = start_x; x <= end_x; x++) {
        for (int z = start_z; z <= end_z; z++) {
            for (int y = start_y; y <= end_y; y++) {
                for (RotationInfo rotationInfo : tops_and_bottoms) {
                    if (rotationInfo.get_rotation() != texture_provider->get_texture(
                            x + rotationInfo.get_x(),
                            y + rotationInfo.get_y(),
                            z + rotationInfo.get_z(),
                            4
                            )) {
                        goto goto_continue;
                    }
                }

                for (RotationInfo rotationInfo : sides) {
                    if (rotationInfo.get_rotation() != texture_provider->get_texture(
                            x + rotationInfo.get_x(),
                            y + rotationInfo.get_y(),
                            z + rotationInfo.get_z(),
                            2
                    )) {
                        goto goto_continue;
                    }
                }

                std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
            }
            goto_continue:;
        }
    }
}

#include <iostream>
#include "TextureFinder.h"

TextureFinder::TextureFinder(int start_x, int end_x, int start_y, int end_y, int start_z, int end_z, Texture * textureProvider)
{
    this->start_x = start_x;
    this->end_x = end_x;
    this->start_y = start_y;
    this->end_y = end_y;
    this->start_z = start_z;
    this->end_z = end_z;
    this->texture_provider = textureProvider;
}

TextureFinder::~TextureFinder() {
    if (this->texture_provider != nullptr) {
        delete this->texture_provider;
    }
}

void TextureFinder::run() {
    // todo: add a elapsed time counter
    // todo: parallelize this with CUDA

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

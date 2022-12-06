#include <iostream>
#include "TextureFinder.h"
#include "csv.hpp"


std::pair<std::vector<RotationInfo>, std::vector<RotationInfo>> get_rotation_info(const std::string & in) {
    std::vector<RotationInfo> tops_and_bottoms;
    std::vector<RotationInfo> sides;


    try {
        csv::CSVReader reader(in);
        for (csv::CSVRow & row : reader) {
            int x = row["x"].get<int>();
            int y = row["y"].get<int>();
            int z = row["z"].get<int>();
            int rotation = row["rotation"].get<int>();
            bool is_side;
            std::istringstream(row["is_side"].get<std::string>()) >> is_side;
            RotationInfo rotation_info = RotationInfo(x, y, z, rotation, is_side);
            if (is_side) {
                sides.push_back(rotation_info);
            } else {
                tops_and_bottoms.push_back(rotation_info);
            }
        }
    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
        exit(2);
    }



    return std::make_pair(tops_and_bottoms, sides);
}

TextureFinder::TextureFinder(const std::string & in, int start_x, int end_x, int start_y, int end_y, int start_z, int end_z, Texture * textureProvider)
{
    this->start_x = start_x;
    this->end_x = end_x;
    this->start_y = start_y;
    this->end_y = end_y;
    this->start_z = start_z;
    this->end_z = end_z;
    this->texture_provider = textureProvider;

    auto rotation_info = get_rotation_info(in);
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

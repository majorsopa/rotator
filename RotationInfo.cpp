#include "RotationInfo.h"
RotationInfo::RotationInfo(int x, int y, int z, int rotation, bool is_side) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->is_side = is_side;
    if (is_side) {
        this->rotation = rotation%2;
    } else {
        this->rotation = rotation;
    }
}

int RotationInfo::get_x() {
    return x;
}

int RotationInfo::get_y() {
    return y;
}

int RotationInfo::get_z() {
    return z;
}

int RotationInfo::get_rotation() {
    return rotation;
}

bool RotationInfo::get_is_side() {
    return is_side;
}

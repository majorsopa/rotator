#include "RotationInfo.h"
RotationInfo::RotationInfo(int x, int y, int z, int rotation, bool is_side) {
    this->x = x;
    this->y = y;
    this->z = z;
    if (is_side) {
        this->rotation = rotation%2;
    } else {
        this->rotation = rotation;
    }
}

int RotationInfo::get_x() const {
    return x;
}

int RotationInfo::get_y() const {
    return y;
}

int RotationInfo::get_z() const {
    return z;
}

int RotationInfo::get_rotation() const {
    return rotation;
}

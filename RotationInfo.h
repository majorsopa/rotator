#ifndef ROTATOR_ROTATIONINFO_H
#define ROTATOR_ROTATIONINFO_H


class RotationInfo {
public:
    RotationInfo(int x, int y, int z, int rotation, bool is_side);
    int get_x();
    int get_y();
    int get_z();
    int get_rotation();
    bool get_is_side();
private:
    int x;
    int y;
    int z;
    int rotation;
    bool is_side;
};


#endif //ROTATOR_ROTATIONINFO_H

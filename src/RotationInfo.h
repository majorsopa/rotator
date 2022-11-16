#ifndef ROTATOR_ROTATIONINFO_H
#define ROTATOR_ROTATIONINFO_H


class RotationInfo {
public:
    RotationInfo(int x, int y, int z, int rotation, bool is_side);
    int get_x() const;
    int get_y() const;
    int get_z() const;
    int get_rotation() const;
    bool get_is_side() const;
private:
    int x;
    int y;
    int z;
    int rotation;
    bool is_side;
};


#endif //ROTATOR_ROTATIONINFO_H

#ifndef ROTATOR_TEXTUREFINDER_H
#define ROTATOR_TEXTUREFINDER_H


#include <vector>
#include "RotationInfo.h"
#include "Texture.h"

class TextureFinder {
public:
    TextureFinder(const std::string& in, int start_x, int end_x, int start_y, int end_y, int start_z, int end_z, Texture * textureProvider);
    ~TextureFinder();
    void run();
private:
    std::vector<RotationInfo> tops_and_bottoms;
    std::vector<RotationInfo> sides;

    int start_x;
    int end_x;
    int start_y;
    int end_y;
    int start_z;
    int end_z;
    Texture *texture_provider;
};


#endif //ROTATOR_TEXTUREFINDER_H

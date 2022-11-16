#ifndef ROTATOR_TEXTUREFINDER_H
#define ROTATOR_TEXTUREFINDER_H


#include <vector>
#include "RotationInfo.h"
#include "textures/Texture.h"

class TextureFinder {
public:
    TextureFinder(int start_x, int end_x, int start_y, int end_y, int start_z, int end_z, Texture *textureProvider);
    ~TextureFinder();
    void run();
private:
    const std::vector<RotationInfo> formation;  // unneeded and will be removed later
    const std::vector<RotationInfo> tops_and_bottoms;
    const std::vector<RotationInfo> sides;

    int start_x;
    int end_x;
    int start_y;
    int end_y;
    int start_z;
    int end_z;
    Texture *texture_provider;
};


#endif //ROTATOR_TEXTUREFINDER_H

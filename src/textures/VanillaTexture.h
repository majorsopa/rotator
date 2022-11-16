#ifndef ROTATOR_VANILLATEXTURE_H
#define ROTATOR_VANILLATEXTURE_H


#include "Texture.h"

class VanillaTexture: public Texture {
public:
    int random_from_seed(signed long long seed) override {
        seed = (seed ^ multiplier) & mask;
        return (signed int)((unsigned long long)(seed * 0xBB20B4600A69ll + 0x40942DE6BAll) >> 16);
    }
private:
    static const signed long long multiplier = 0x5DEECE66D;
    constexpr static const signed long long mask = (1ll << 48) - 1;
};


#endif //ROTATOR_VANILLATEXTURE_H

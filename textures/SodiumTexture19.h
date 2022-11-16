#ifndef ROTATOR_SODIUMTEXTURE19_H
#define ROTATOR_SODIUMTEXTURE19_H

#include <bit>
#include "SodiumTexture.h"

class SodiumTexture19 : public SodiumTexture {
public:
    int random_from_seed(signed long long seed) override {
        signed long long lo = seed ^ 7640891576956012809ll;
        signed long long hi = lo + -7046029254386353131ll;

        auto nlo = (unsigned long long)stafford_mix_13(lo);
        auto nhi = (unsigned long long)stafford_mix_13(hi);

        return (int)(std::rotl(nlo + nhi, 17) + nlo);
    }
};

#endif //ROTATOR_SODIUMTEXTURE19_H

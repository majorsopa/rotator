#ifndef ROTATOR_SODIUMTEXTURE_H
#define ROTATOR_SODIUMTEXTURE_H


#include "Texture.h"

class SodiumTexture : public Texture {

public:
    int random_from_seed(signed long long seed) override {
        auto x = (unsigned long long) seed;
        seed ^= (signed long long)(x >> 33);
        seed *= 0xFF51AFD7ED558CCDll;
        x = (unsigned long long) seed;
        seed ^= (signed long long)(x >> 33);
        seed *= 0xC4CEB9FE1A85EC53ll;
        x = (unsigned long long) seed;
        seed ^= (signed long long)(x >> 33);

        seed += PHI;
        signed long long rand1 = stafford_mix_13(seed);
        signed long long rand2 = stafford_mix_13(seed + PHI);

        return (int) (rand1 + rand2);
    }
protected:
    static signed long long stafford_mix_13(signed long long z) {
        auto x = (unsigned long long) z;
        z = (z ^ (signed long long)(x >> 30)) * 0xBF58476D1CE4E5B9ll;
        x = (unsigned long long) z;
        z = (z ^ (signed long long)(x >> 27)) * 0x94D049BB133111EBll;
        x = (unsigned long long) z;

        return z ^ (signed long long)(x >> 31);
    }
private:
    static const signed long long PHI = 0x9E3779B97F4A7C15ll;
};


#endif //ROTATOR_SODIUMTEXTURE_H

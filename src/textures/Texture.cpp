#include <bit>
#include "TextureType.h"
#include "Texture.h"

namespace version_functions {
    static signed long long stafford_mix_13(signed long long z) {
        auto x = (unsigned long long) z;
        z = (z ^ (signed long long)(x >> 30)) * 0xBF58476D1CE4E5B9ll;
        x = (unsigned long long) z;
        z = (z ^ (signed long long)(x >> 27)) * 0x94D049BB133111EBll;
        x = (unsigned long long) z;

        return z ^ (signed long long)(x >> 31);
    }


    int vanilla_random_from_seed(signed long long seed) {
        const signed long long mask = (1ll << 48) - 1;
        const signed long long multiplier = 0x5DEECE66D;
        seed = (seed ^ multiplier) & mask;
        return (signed int)((unsigned long long)(seed * 0xBB20B4600A69ll + 0x40942DE6BAll) >> 16);
    }

    int sodium_random_from_seed(signed long long seed) {
        const signed long long phi = 0x9E3779B97F4A7C15ll;

        auto x = (unsigned long long) seed;
        seed ^= (signed long long)(x >> 33);
        seed *= 0xFF51AFD7ED558CCDll;
        x = (unsigned long long) seed;
        seed ^= (signed long long)(x >> 33);
        seed *= 0xC4CEB9FE1A85EC53ll;
        x = (unsigned long long) seed;
        seed ^= (signed long long)(x >> 33);

        seed += phi;
        signed long long rand1 = stafford_mix_13(seed);
        signed long long rand2 = stafford_mix_13(seed + phi);

        return (int) (rand1 + rand2);
    }

    int sodium19_random_from_seed(signed long long seed) {
        signed long long lo = seed ^ 7640891576956012809ll;
        signed long long hi = lo + -7046029254386353131ll;

        auto nlo = (unsigned long long)stafford_mix_13(lo);
        auto nhi = (unsigned long long)stafford_mix_13(hi);

        return (int)(std::rotl(nlo + nhi, 17) + nlo);
    }
}

int Texture::random_from_seed(signed long long seed) {
    using namespace version_functions;
    int ret;
    switch (this->texture_type) {
        case TextureType::VANILLA:
            ret = vanilla_random_from_seed(seed);
            break;
        case TextureType::SODIUM:
            ret = sodium_random_from_seed(seed);
            break;
        case TextureType::SODIUM19:
            ret = sodium19_random_from_seed(seed);
            break;
    }
    return ret;
}

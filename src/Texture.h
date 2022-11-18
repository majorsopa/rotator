#ifndef ROTATOR_TEXTURE_H
#define ROTATOR_TEXTURE_H


#include "TextureType.h"



class Texture {
private:
    TextureType texture_type;
    static signed long long get_coordinate_random(int x, int y, int z) {
        signed long long l = (signed long long)(x * 3129871) ^ (signed long long)z * 116129781ll ^ (signed long long)y;
        l = l * l * 42317861ll + l * 11ll;
        return l >> 16;
    }

    int random_from_seed(signed long long seed);
public:
    explicit Texture(TextureType texture_type) {
        this->texture_type = texture_type;
    }

    int get_texture(int x, int y, int z, int mod) {
        int rand = random_from_seed(get_coordinate_random(x, y, z));
        return (rand < 0 ? -rand : rand) % mod;
    }

    ~Texture() = default;
};


#endif //ROTATOR_TEXTURE_H

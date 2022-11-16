// todo: make proper unit tests

#include <iostream>
#include "textures/Texture.h"


bool vanilla_tests() {
    auto provider = std::make_unique<Texture>(TextureType::VANILLA);
    bool passed = true;
    if (provider->get_texture(-1, 0, -1, 4) != 0) {
        std::cout << "fail at `-1 0 -1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(0, 0, -1, 4) != 1) {
        std::cout << "fail at `0 0 -1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, 0, -1, 4) != 0) {
        std::cout << "fail at `1 0 -1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-2, 0, 0, 4) != 2) {
        std::cout << "fail at `-2 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-1, 0, 0, 4) != 0) {
        std::cout << "fail at `-1 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(0, 0, 0, 4) != 0) {
        std::cout << "fail at `0 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, 0, 0, 4) != 1) {
        std::cout << "fail at `1 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-1, 0, 1, 4) != 0) {
        std::cout << "fail at `-1 0 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(0, 0, 1, 4) != 3) {
        std::cout << "fail at `0 0 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, 0, 1, 4) != 0) {
        std::cout << "fail at `1 0 1" << std::endl;
        passed = false;
    }


    if (provider->get_texture(-6, 0, 0, 2) != 1) {
        std::cout << "fail at `-6 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-5, 0, 0, 2) != 0) {
        std::cout << "fail at `-5 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-4, 0, 0, 2) != 1) {
        std::cout << "fail at `-4 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-3, 0, 0, 2) != 1) {
        std::cout << "fail at `-3 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-2, 0, 0, 2) != 0) {
        std::cout << "fail at `-2 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(-1, 0, 0, 2) != 0) {
        std::cout << "fail at `-1 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(0, 0, 0, 2) != 0) {
        std::cout << "fail at `0 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, 0, 0, 2) != 1) {
        std::cout << "fail at `1 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(2, 0, 0, 2) != 0) {
        std::cout << "fail at `2 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(3, 0, 0, 2) != 0) {
        std::cout << "fail at `3 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(4, 0, 0, 2) != 1) {
        std::cout << "fail at `4 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(5, 0, 0, 2) != 1) {
        std::cout << "fail at `5 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(6, 0, 0, 2) != 0) {
        std::cout << "fail at `6 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(7, 0, 0, 2) != 1) {
        std::cout << "fail at `7 0 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(8, 0, 0, 2) != 0) {
        std::cout << "fail at `8 0 0" << std::endl;
        passed = false;
    }

    return passed;
}

bool sodium_tests() {
    auto provider = std::make_unique<Texture>(TextureType::SODIUM);
    bool passed = true;
    if (provider->get_texture(0, -56, 0, 4) != 3) {
        std::cout << "fail at `0 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, -56, 0, 4) != 3) {
        std::cout << "fail at `1 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(2, -56, 0, 4) != 3) {
        std::cout << "fail at `2 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(3, -56, 0, 4) != 3) {
        std::cout << "fail at `3 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(4, -56, 0, 4) != 1) {
        std::cout << "fail at `4 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(5, -56, 0, 4) != 3) {
        std::cout << "fail at `5 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(6, -56, 0, 4) != 0) {
        std::cout << "fail at `6 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(7, -56, 0, 4) != 2) {
        std::cout << "fail at `7 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(8, -56, 0, 4) != 0) {
        std::cout << "fail at `8 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(9, -56, 0, 4) != 3) {
        std::cout << "fail at `9 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(10, -56, 0, 4) != 1) {
        std::cout << "fail at `10 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(11, -56, 0, 4) != 1) {
        std::cout << "fail at `11 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(12, -56, 0, 4) != 3) {
        std::cout << "fail at `12 -56 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(13, -56, 0, 4) != 3) {
        std::cout << "fail at `13 -56 0" << std::endl;
        passed = false;
    }

    if (provider->get_texture(0, -56, 1, 2) != 1) {
        std::cout << "fail at `0 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, -56, 1, 2) != 1) {
        std::cout << "fail at `1 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(2, -56, 1, 2) != 1) {
        std::cout << "fail at `2 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(3, -56, 1, 2) != 0) {
        std::cout << "fail at `3 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(4, -56, 1, 2) != 0) {
        std::cout << "fail at `4 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(5, -56, 1, 2) != 0) {
        std::cout << "fail at `5 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(6, -56, 1, 2) != 1) {
        std::cout << "fail at `6 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(7, -56, 1, 2) != 1) {
        std::cout << "fail at `7 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(8, -56, 1, 2) != 1) {
        std::cout << "fail at `8 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(9, -56, 1, 2) != 0) {
        std::cout << "fail at `9 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(10, -56, 1, 2) != 1) {
        std::cout << "fail at `10 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(11, -56, 1, 2) != 1) {
        std::cout << "fail at `11 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(12, -56, 1, 2) != 1) {
        std::cout << "fail at `12 -56 1" << std::endl;
        passed = false;
    }
    if (provider->get_texture(13, -56, 1, 2) != 1) {
        std::cout << "fail at `13 -56 1" << std::endl;
        passed = false;
    }

    return passed;
}

bool sodium19_tests() {
    auto provider = std::make_unique<Texture>(TextureType::SODIUM19);
    bool passed = true;
    if (provider->get_texture(0, -61, 0, 4) != 1) {
        std::cout << "fail at `0 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(1, -61, 0, 4) != 1) {
        std::cout << "fail at `1 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(2, -61, 0, 4) != 0) {
        std::cout << "fail at `2 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(3, -61, 0, 4) != 2) {
        std::cout << "fail at `3 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(4, -61, 0, 4) != 0) {
        std::cout << "fail at `4 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(5, -61, 0, 4) != 3) {
        std::cout << "fail at `5 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(6, -61, 0, 4) != 1) {
        std::cout << "fail at `6 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(7, -61, 0, 4) != 2) {
        std::cout << "fail at `7 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(8, -61, 0, 4) != 2) {
        std::cout << "fail at `8 -61 0" << std::endl;
        passed = false;
    }
    if (provider->get_texture(9, -61, 0, 4) != 1) {
        std::cout << "fail at `9 -61 0" << std::endl;
        passed = false;
    }

    return passed;
}



void run_verification() {
    std::cout << "starting" << std::endl;
    std::cout << "------" << std::endl;
    std::cout << "--- vanilla tests ---" << std::endl;
    if (vanilla_tests()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << "--- sodium tests ---" << std::endl;
    if (sodium_tests()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << "--- sodium19 tests ---" << std::endl;
    if (sodium19_tests()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << "------" << std::endl;
    std::cout << "done" << std::endl;
}
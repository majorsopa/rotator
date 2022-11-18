#include <sys/stat.h>
#include "verifier.h"
#include "TextureFinder.h"

inline bool file_exists (const std::string& name) {
    struct stat buffer{};
    return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        run_verification();
    } else if (argc == 2) {
        if (!file_exists(argv[1])) {
            std::cout << "File does not exist" << std::endl;
            return 1;
        }
        std::cout << "starting search" << std::endl;
        TextureFinder texture_finder = TextureFinder(argv[1], -10000, 10000, 10, 60, -10000, 10000, new Texture(TextureType::VANILLA));
        texture_finder.run();
        std::cout << "done" << std::endl;
    }
    return 0;
}

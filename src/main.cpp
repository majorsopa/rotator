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
    } else if (argc == 8) {
        if (!file_exists(argv[1])) {
            std::cout << "File does not exist" << std::endl;
            return 1;
        }
        std::cout << "starting search" << std::endl;

        int start_x = std::strtol(argv[2], nullptr, 10);
        int end_x = std::strtol(argv[3], nullptr, 10);
        int start_y = std::strtol(argv[4], nullptr, 10);
        int end_y = std::strtol(argv[5], nullptr, 10);
        int start_z = std::strtol(argv[6], nullptr, 10);
        int end_z = std::strtol(argv[7], nullptr, 10);

        std::cout << start_x << " " << end_x << " " << start_y << " " << end_y << " " << start_z << " " << end_z << std::endl;

        TextureFinder texture_finder = TextureFinder(argv[1], start_x, end_x, start_y, end_y, start_z, end_z, new Texture(TextureType::SODIUM19));
        texture_finder.run();
        std::cout << "done" << std::endl;
    }
    return 0;
}

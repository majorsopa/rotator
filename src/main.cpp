#include <sys/stat.h>
#include <thread>
#include "verifier.h"
#include "TextureFinder.h"
#include "csv.hpp"

inline bool file_exists (const std::string& name) {
    struct stat buffer{};
    return (stat (name.c_str(), &buffer) == 0);
}

std::pair<std::vector<RotationInfo>, std::vector<RotationInfo>> get_rotation_info(const std::string & in) {
    std::vector<RotationInfo> tops_and_bottoms;
    std::vector<RotationInfo> sides;


    try {
        csv::CSVReader reader(in);
        for (csv::CSVRow & row : reader) {
            int x = row["x"].get<int>();
            int y = row["y"].get<int>();
            int z = row["z"].get<int>();
            int rotation = row["rotation"].get<int>();
            bool is_side;
            std::istringstream(row["is_side"].get<std::string>()) >> is_side;
            RotationInfo rotation_info = RotationInfo(x, y, z, rotation, is_side);
            if (is_side) {
                sides.push_back(rotation_info);
            } else {
                tops_and_bottoms.push_back(rotation_info);
            }
        }
    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
        exit(2);
    }



    return std::make_pair(tops_and_bottoms, sides);
}

class RunnableTextureFinder {
    public:
        void operator()(std::unique_ptr<TextureFinder> textureFinder) {
            textureFinder->run();
        }
};

int main(int argc, char *argv[]) {
    if (argc == 1) {
        run_verification();
    } else {
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
        int num_threads = std::strtol(argv[8], nullptr, 10);
        int mode = std::strtol(argv[9], nullptr, 10);

        TextureType texture_type;
        if (mode == 0) {
            texture_type = TextureType::VANILLA;
        } else if (mode == 1) {
            texture_type = TextureType::SODIUM;
        } else if (mode == 2) {
            texture_type = TextureType::SODIUM19;
        } else {
            std::cout << "invalid mode" << std::endl;
            return 1;
        };

        auto rotation_info = get_rotation_info(argv[1]);

        std::cout << start_x << " " << end_x << " " << start_y << " " << end_y << " " << start_z << " " << end_z << std::endl;

        int per_y = (end_y - start_y) / num_threads;
        std::vector<std::thread> threads;
        for (int i = 0; i < num_threads; i++) {
            int start_y_thread = start_y + i * per_y;
            int end_y_thread = start_y + (i + 1) * per_y;
            if (i == num_threads - 1) {
                end_y_thread = end_y;
            }
            threads.emplace_back(RunnableTextureFinder(), std::make_unique<TextureFinder>(rotation_info, start_x, end_x, start_y_thread, end_y_thread, start_z, end_z, new Texture(texture_type)));
        }

        for (auto & thread : threads) {
            thread.join();
        }


        std::cout << "done" << std::endl;
    }
    return 0;
}

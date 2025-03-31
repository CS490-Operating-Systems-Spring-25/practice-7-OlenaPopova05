#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

int main() {
    std::string directory = "directory";

    if (!std::filesystem::exists(directory)) {
        if (!std::filesystem::create_directory(directory)) {
            std::cerr << "Error creating directory " << directory << "\n";
            return 1;
        }
    }

    std::vector<std::ofstream> files;

    for (int i = 0; i < 1000; ++i) {
        std::string fileName = directory + "/file_" + std::to_string(i) + ".txt";

        std::ofstream file(fileName);
        if (!file) {
            std::cerr << "Error opening file " << i << "\n";
            break;
        }
        files.push_back(std::move(file));
    }

    std::cout << "Opened " << files.size() << " files in directory " << directory << ".\n";
    std::cin.get();

    return 0;
}

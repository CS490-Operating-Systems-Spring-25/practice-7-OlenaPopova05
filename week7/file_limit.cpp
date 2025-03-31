#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <filesystem>

int main() {
    std::string directory = "directory2";

    if (!std::filesystem::exists(directory)) {
        if (!std::filesystem::create_directory(directory)) {
            std::cerr << "Error creating directory " << directory << "\n";
            return 1;
        }
    }

    std::vector<std::ofstream> files;

    for (int batch = 0; batch < 100; ++batch) {
        for (int i = 0; i < 1000; ++i) {
            std::string fileName = directory + "/batch_" + std::to_string(batch) + "_file_" + std::to_string(i) + ".txt";
            std::ofstream file(fileName);
            if (!file) {
                std::cerr << "Error opening file after " << (batch * 1000 + i) << " files.\n";
                return 1;
            }
            files.push_back(std::move(file));
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Opened " << files.size() << " files in directory " << directory << ".\n";
    std::cin.get();
    return 0;
}

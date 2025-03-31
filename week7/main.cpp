#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

int main() {
    std::ofstream file("test.txt");
    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    for (int i = 0; i < 1000; ++i) {
        file << "Iteration " << i << "\n";
        file.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

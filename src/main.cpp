
#include <fstream>

#include "util/util.h"
#include "games/games.h"

int main() {
    // std::ifstream input{"words.txt"};
    // input.open("words.txt");
    // std::string line;
    // while (std::getline(input, line)) {
    //     // using printf() in all tests for consistency
    //     std::cout << line;
    // }
    // input.close();
    // return 0;
    std::println("Choose game");
    std::println("1. LoremWorld");
    std::println("2. Calculator");
    switch (util::unwrap(util::read_int())) {
        case 1:
            return games::lorem_world();
        case 2:
            return games::calculator();
        default:
            std::cerr << "Wrong game!" << std::endl;
            return EXIT_FAILURE;
    }
}





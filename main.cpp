#include "game.hpp"
#include <iostream>

int main() {
    try {
    OGame game;
    game.run();
    }
    catch (const std::exception& e) {
        // std::cerr << e.what() << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
#include "player.h"
#include "pokemon.h"

Player::Player(const std::string& s): Trainer(s) {}

Move* Player::getMove() const {
    std::string n;
    const int max = lead->moveCount();
    std::cout << *lead << std::endl;
    std::cout << "Select a move (1 -- " << max << "): ";
    while (true) {
        std::cin >> n;
        try {
            const int index = std::stoi(n);
            if (index > 0 && index <= max) {
                return lead->getMove(static_cast<size_t>(index - 1));
            }
        } catch (std::invalid_argument&) {}
        std::cerr << "Enter a valid index: ";
    }
}

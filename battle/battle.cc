#include "battle.h"
#include "exceptions.h"
#include <iostream>

Battle::~Battle() = default;

void Battle::start() {
    try {
        initialMessage();
        turn();
        endMessage();
    } catch (BattleError& be) {
        std::cerr << be.what() << std::endl;
    }
}

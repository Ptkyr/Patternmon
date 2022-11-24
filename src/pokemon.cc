#include "pokemon.h"
#include "move.h"
#include "exceptions.h"
#include "water.h"
#include "fire.h"
#include "grass.h"
#include "types.h"
#include <iostream>

Pokemon::Pokemon(const std::string& n, Stats s):
        name{n}, stats{s}, moves{}, hp{2 * stats.hp + level + 10}, max_hp{this->hp} {}

Pokemon::~Pokemon() {
    for (auto& m: moves) {
        delete m;
    }
}

void Pokemon::learn(Move* m) {
    if (moves.size() == 4) {
        throw FourMoves{};
    }
    moves.emplace_back(m);
    std::cout << name << " learned " << m->getName() << "!" << std::endl;
}

void Pokemon::forget(Move* m, const int n) {
    delete moves[n];
    moves[n] = m;
}

void Pokemon::attack(Pokemon& p) const {
    for (const auto& m: moves) {
        std::cout << name << " used " << m->getName() << "!" << std::endl;
        m->hit(p);
    }
}

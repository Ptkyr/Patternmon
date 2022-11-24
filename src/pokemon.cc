#include "pokemon.h"
#include "move.h"
#include "exceptions.h"
#include "water.h"
#include "fire.h"
#include "grass.h"
#include "types.h"
#include <iostream>

Pokemon::Pokemon(std::string& n, int hp, int atk, int def, int spatk, int spdef, int spe):
        name{n}, moves{}, hp{2 * hp + level + 10}, max_hp{this->hp} {
    stats.reserve(6);
    stats.emplace_back(hp);
    stats.emplace_back(atk);
    stats.emplace_back(def);
    stats.emplace_back(spatk);
    stats.emplace_back(spdef);
    stats.emplace_back(spe);
}

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

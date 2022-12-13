#include "pokemon.h"
#include "move.h"
#include "exceptions.h"
#include "water.h"
#include "fire.h"
#include "grass.h"
#include "types.h"
#include <iostream>
#include <random>

Pokemon::Pokemon(const std::string& n, Stats s):
        name{n}, stats{s}, moves{}, hp{2 * stats.hp + level + 10}, max_hp{this->hp} {}

Pokemon::~Pokemon() = default;

void Pokemon::learn(std::shared_ptr<Move> m) {
    if (moves.size() == 4) {
        throw FourMovesExcept{name};
    }
    moves.emplace_back(m);
    std::cout << name << " learned " << m->getName() << "!" << std::endl;
}

void Pokemon::attack(Pokemon& p) const {
    if (moves.size() == 0) throw NoMovesExcept{name};
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dist{0, static_cast<int>(moves.size() - 1)};
    Move* m = moves[dist(gen)].get();
    std::cout << name << " used " << m->getName() << "!" << std::endl;
    if (m->getPP() <= 0) throw NoPPExcept{};
    m->hit(p);
    m->use();
}

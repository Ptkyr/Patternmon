#include "move.h"
#include "pokemon.h"

Move::Move(std::string n, Category c, int base, int acc, int pp): 
    name{n}, cat{c}, bp{base}, acc{acc}, pp{pp} {}

Move::~Move() = default;

int Move::getBP() const {
    return bp;
}

int Move::getAcc() const {
    return acc;
}

int Move::getPP() const {
    return pp;
}

Category Move::getPS() const {
    return cat;
}

std::string Move::getName() const {
    return name;
}

void Move::use() {
    --pp;
}

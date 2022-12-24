#include "species.h"
#include "move.h"
#include "types.h"
#include <iostream>

Species::Species(std::string name, Stats s): Pokemon(name, s) {}

void Species::calcDamage(Move& m, const double mult) {
    double tmp = (2 * level / 5 + 2) * m.getBP() / 50;
    if (m.getPS() == Category::Physical) {
        tmp *= 100.0 / stats.def;
    } else {
        tmp *= 100.0 / stats.spdef;
    }
    const int dmg = tmp * mult;
    std::cout << name << " took " << dmg << " damage!" << std::endl;
    hp -= dmg;
    if (hp > 0) {
        std::cout << name << " has " << hp << "/" << max_hp << " HP left." << std::endl;
    } else {
        std::cout << name << " fainted!" << std::endl;
    }
}

void Species::printHit(const double mult) const {
    if (mult > 1) {
        std::cout << "It's super effective!" << std::endl;
    } else if (mult < 1) {
        std::cout << "It's not very effective..." << std::endl;
    }
}

void Species::helpHit(Move& m, const double mult) {
    if (hp <= 0) return;
    printHit(mult);
    calcDamage(m, mult);
}

void Species::hitBy(WaterMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(FireMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(GrassMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(ElectricMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(GroundMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(NormalMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(IceMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(FightingMove& wm, const double mult) {
    helpHit(wm, mult);
}

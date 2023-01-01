#include "species.h"
#include "move.h"
#include "types.h"
#include "exceptions.h"
#include <iostream>
#include <random>

Species::Species(const std::string& n, Stats s):
        name{n}, stats{s}, moves{}, hp{2 * stats.hp + level + 10}, max_hp{this->hp} {}

Species::~Species() = default;

bool Species::fainted() const {
    return (hp <= 0);
}

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
    if (mult == 0) {
        std::cout << "It didn't affect " << name << "..." << std::endl;
    } else if (mult < 1) {
        std::cout << "It's not very effective..." << std::endl;
    } else if (mult > 1) {
        std::cout << "It's super effective!" << std::endl;
    }
}

void Species::learn(std::unique_ptr<Move> m) {
    if (moves.size() == 4) {
        throw FourMovesExcept{name};
    }
    // std::cout << name << " learned " << m->getName() << "!" << std::endl;
    moves.emplace_back(std::move(m));
}

void Species::attack(Pokemon& p) const {
    if (moves.size() == 0) throw NoMovesExcept{name};
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dist{0, static_cast<int>(moves.size() - 1)};
    Move* m = moves[static_cast<size_t>(dist(gen))].get();
    std::cout << name << " used " << m->getName() << "!" << std::endl;
    if (m->getPP() <= 0) throw NoPPExcept{};
    m->hit(p);
    m->use();
}

void Species::accuracyCheck(const Move& m) const {
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dist{1, 100};
    const int tmp = dist(gen);
    if (m.getAcc() < tmp) throw AttackMiss{};
}

void Species::helpHit(Move& m, const double mult) {
    if (fainted()) return;
    try {
        accuracyCheck(m);
    } catch (MoveExcept& me) {
        std::cout << me.what() << std::endl;
        return;
    }
    printHit(mult);
    if (mult == 0) return;
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

void Species::hitBy(PoisonMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(FlyingMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(PsychicMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(BugMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(RockMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(GhostMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(DragonMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(DarkMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(SteelMove& wm, const double mult) {
    helpHit(wm, mult);
}

void Species::hitBy(FairyMove& wm, const double mult) {
    helpHit(wm, mult);
}

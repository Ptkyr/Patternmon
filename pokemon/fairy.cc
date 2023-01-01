#include "fairy.h"

Fairy::Fairy(Pokemon* ptr): PokemonDecorator(ptr) {}

void Fairy::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fairy::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Fairy::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fairy::hitBy(DragonMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}

void Fairy::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fairy::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

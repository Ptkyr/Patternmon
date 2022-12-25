#include "fairy.h"

Fairy::Fairy(Pokemon* p): PokemonDecorator(p) {}

void Fairy::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fairy::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Fairy::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fairy::hitBy(DragonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Fairy::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Fairy::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

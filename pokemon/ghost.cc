#include "ghost.h"

Ghost::Ghost(Pokemon* p): PokemonDecorator(p) {}

void Ghost::hitBy(NormalMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Ghost::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Ghost::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Ghost::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Ghost::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ghost::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

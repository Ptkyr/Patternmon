#include "ghost.h"

Ghost::Ghost(Pokemon* ptr): PokemonDecorator(ptr) {}

void Ghost::hitBy(NormalMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}

void Ghost::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}

void Ghost::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Ghost::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Ghost::hitBy(GhostMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ghost::hitBy(DarkMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

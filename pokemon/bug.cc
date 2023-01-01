#include "bug.h"

Bug::Bug(Pokemon* p): PokemonDecorator(p) {}

void Bug::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Bug::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Bug::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Bug::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Bug::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Bug::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

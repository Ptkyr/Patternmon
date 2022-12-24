#include "bug.h"

Bug::Bug(Pokemon* p): PokemonDecorator(p) {}

void Bug::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Bug::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Bug::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Bug::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Bug::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Bug::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

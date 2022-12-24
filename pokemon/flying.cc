#include "flying.h"

Flying::Flying(Pokemon* p): PokemonDecorator(p) {}

void Flying::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Flying::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Flying::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Flying::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Flying::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Flying::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Flying::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

#include "flying.h"

Flying::Flying(Pokemon* ptr): PokemonDecorator(ptr) {}

void Flying::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Flying::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Flying::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Flying::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Flying::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}

void Flying::hitBy(BugMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Flying::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

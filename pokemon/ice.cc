#include "ice.h"

Ice::Ice(Pokemon* ptr): PokemonDecorator(ptr) {}

void Ice::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ice::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Ice::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ice::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ice::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

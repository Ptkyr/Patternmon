#include "ice.h"

Ice::Ice(Pokemon* p): PokemonDecorator(p) {}

void Ice::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ice::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Ice::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ice::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ice::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

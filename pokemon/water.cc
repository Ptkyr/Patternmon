#include "water.h"

Water::Water(Pokemon* p): PokemonDecorator(p) {}

void Water::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Water::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Water::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Water::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Water::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Water::hitBy(SteelMove& gm, const double mult) {
    p->hitBy(gm, mult * 0.5);
}

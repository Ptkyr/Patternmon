#include "water.h"

Water::Water(Pokemon* ptr): PokemonDecorator(ptr) {}

void Water::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Water::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Water::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Water::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Water::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Water::hitBy(SteelMove& gm, const double mult) {
    p->hitBy(gm, mult * NVERYEFF);
}

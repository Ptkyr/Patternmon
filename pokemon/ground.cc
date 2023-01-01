#include "ground.h"

Ground::Ground(Pokemon* ptr): PokemonDecorator(ptr) {}

void Ground::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ground::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ground::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * IMMUNITY);
}

void Ground::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Ground::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Ground::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

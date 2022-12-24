#include "ground.h"

Ground::Ground(Pokemon* p): PokemonDecorator(p) {}

void Ground::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ground::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ground::hitBy(ElectricMove& wm, const double mult) {
    p->hitBy(wm, mult * 0);
}

void Ground::hitBy(IceMove& wm, const double mult) {
    p->hitBy(wm, mult * 2);
}

void Ground::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

void Ground::hitBy(RockMove& wm, const double mult) {
    p->hitBy(wm, mult * 0.5);
}

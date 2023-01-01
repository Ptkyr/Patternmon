#include "rock.h"

Rock::Rock(Pokemon* p): PokemonDecorator(p) {}

void Rock::hitBy(NormalMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Rock::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Rock::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Rock::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Rock::hitBy(FightingMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Rock::hitBy(PoisonMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Rock::hitBy(GroundMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Rock::hitBy(FlyingMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Rock::hitBy(SteelMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

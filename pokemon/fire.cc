#include "fire.h"

Fire::Fire(Pokemon* p): PokemonDecorator(p) {}

void Fire::hitBy(FireMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fire::hitBy(WaterMove& wm, const double mult) {
    p->hitBy(wm, mult * SUPEREFF);
}

void Fire::hitBy(GrassMove& wm, const double mult) {
    p->hitBy(wm, mult * NVERYEFF);
}

void Fire::hitBy(IceMove& gm, const double mult) {
    p->hitBy(gm, mult * NVERYEFF);
}

void Fire::hitBy(GroundMove& gm, const double mult) {
    p->hitBy(gm, mult * SUPEREFF);
}

void Fire::hitBy(BugMove& gm, const double mult) {
    p->hitBy(gm, mult * NVERYEFF);
}

void Fire::hitBy(RockMove& gm, const double mult) {
    p->hitBy(gm, mult * SUPEREFF);
}

void Fire::hitBy(SteelMove& gm, const double mult) {
    p->hitBy(gm, mult * NVERYEFF);
}

void Fire::hitBy(FairyMove& gm, const double mult) {
    p->hitBy(gm, mult * NVERYEFF);
}
